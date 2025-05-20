//FormAI DATASET v1.0 Category: Image Steganography ; Style: paranoid
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define FILE_MAX_SIZE 1024   //Maximum File Size to hide the message
#define BITS_PER_BYTE 8      //There are 8 bits per byte in a byte

typedef union {
    unsigned char byte;
    struct { //bits in byte stored in descending order
        unsigned char bit7:1;
        unsigned char bit6:1;
        unsigned char bit5:1;
        unsigned char bit4:1;
        unsigned char bit3:1;
        unsigned char bit2:1;
        unsigned char bit1:1;
        unsigned char bit0:1;
    } bit;
} BYTE_BIT;

typedef struct {      
    long int begin_pos;     
    long int end_pos;       
} FILE_SEGMENT; 

const char *END_HEADER = "*_END_*";   

unsigned char set_bit(unsigned char byte, int bit_position)
{   //set bit_position-th bit of byte to 1
    BYTE_BIT bit;
    bit.byte = byte;
    switch(bit_position) {
        case 0: bit.bit.bit0 = 1; break;
        case 1: bit.bit.bit1 = 1; break;
        case 2: bit.bit.bit2 = 1; break;
        case 3: bit.bit.bit3 = 1; break;
        case 4: bit.bit.bit4 = 1; break;
        case 5: bit.bit.bit5 = 1; break;
        case 6: bit.bit.bit6 = 1; break;
        case 7: bit.bit.bit7 = 1; break;
    }
    return bit.byte;    //returning new byte
}

void encode(FILE* input_file_ptr, FILE* output_file_ptr, char* text_to_embed)  
{
    FILE_SEGMENT file_segment;
    long int file_segment_size;     //size of file_segment that can be used for storing message
    int bit_position;               //current bit position of message character
    char character;                 
    unsigned char byte;             //file byte being manipulated with set_bit()
    char *encoded_text = malloc(strlen(text_to_embed)*BITS_PER_BYTE+16); //Allocate memory for encoded message
    memset(encoded_text, 0, strlen(text_to_embed)*BITS_PER_BYTE+16);   
    sprintf(encoded_text,"%s%s",text_to_embed,END_HEADER);
    bit_position = 0;
    while(*encoded_text) {          //Iterate through every character in message
        character = *encoded_text++;
        for(int i=0; i<BITS_PER_BYTE; ++i) {
            byte = fgetc(input_file_ptr);
            if (feof(input_file_ptr)) {
                printf("Input file is too small, no enough available space to embed the message.\n");
                free(encoded_text);
                return;
            }

            if(byte == '\0') {      //byte value 0 might signal end of text
                file_segment.end_pos = ftell(input_file_ptr) - 1;
                fseek(input_file_ptr, file_segment.begin_pos, SEEK_SET);
                file_segment_size = file_segment.end_pos - file_segment.begin_pos + 1;
                printf("Input file region %ld to %ld can hold only %ld bits. Stopping the encoding.\n", 
                    file_segment.begin_pos, file_segment.end_pos, file_segment_size);
                free(encoded_text);
                return;
            }

            byte = set_bit(byte, bit_position%8);  //setting i-th bit of byte to i-th bit of message character
            fputc(byte, output_file_ptr);
            if(bit_position%BITS_PER_BYTE == BITS_PER_BYTE-1) {     //if message character consumed
                ++file_segment.begin_pos;
                ++file_segment.end_pos;
                bit_position = 0;
            }
            else {
                ++bit_position;
            }
        }
    }
    fseek(input_file_ptr, 0, SEEK_END);     //Go to the end of the input file and write the rest of the file there
    while((byte=fgetc(input_file_ptr)) != EOF) fputc(byte, output_file_ptr);
    free(encoded_text);
}

void decode(FILE* input_file_ptr, char* output_file_name)
{
    FILE* output_file_ptr = fopen(output_file_name, "wb");   //opening file for writing the message
    if(output_file_ptr == NULL) {
        printf("Can not open %s file for writing.\n", output_file_name);
        return;
    }

    char buffer[8+6+1];     //buffer to hold message being read from input file
    long int current_pos = 0;
    int message_length;
    int text_index = 0;
    char message_buffer[FILE_MAX_SIZE] = {0};   //the text that will be extracted from the file
    buffer[8+6] = '\0';     //Terminating the buffer

    while(1) {      //Iterating through every byte
        for(int i=0; i<8; ++i) {    //Iterating through every bit of a byte
            buffer[i] = fgetc(input_file_ptr);
            if(feof(input_file_ptr)) {
                printf("Error. Embedded message header not found.\n");
                fclose(output_file_ptr);
                remove(output_file_name);
                return;
            }
        }

        if(buffer[0] != '!' || buffer[1] != '#' || buffer[2] != 'M' || buffer[3] != 'S' || buffer[4] != 'G' || buffer[5] != '@') {  
            continue;   //if it doesn't start with "!#MSG@", continue to next byte
        }
        message_length = (buffer[6] + (buffer[7] << 8)) * BITS_PER_BYTE;   //Get message size
        if(message_length > FILE_MAX_SIZE) {
            printf("Maximum size of the hidden message cannot exceed %d bytes.\n", FILE_MAX_SIZE);
            fclose(output_file_ptr);
            remove(output_file_name);
            return;
        }

        current_pos += 8;   //Include in current position next 8 bytes already read previously for message length
        fseek(input_file_ptr, current_pos, SEEK_SET);

        if(fread(message_buffer, 1, message_length, input_file_ptr) < message_length) {    //Copy message to message buffer
            printf("Error while reading message from the input file.\n");
            fclose(output_file_ptr);
            remove(output_file_name);
            return;
        }

        break;
    }

    char *end_of_header = strstr(message_buffer, END_HEADER);
    if(end_of_header == NULL) {
        printf("Error. Embedded message header not found.\n");
        fclose(output_file_ptr);
        remove(output_file_name);
        return;
    }

    *end_of_header = '\0'; //End of message replaced with null terminator
    message_length = strlen(message_buffer);    
    for(int i=0; i<message_length; ++i) {
        for(int j=0; j<BITS_PER_BYTE; ++j) {
            unsigned char byte = message_buffer[i];
            byte >>= (BITS_PER_BYTE-j-1);
            if(byte & 0x01) {   //Checking if the j-th bit is 1
                byte = set_bit('\0', text_index%8);   //if it is, then set the text_index-th bit of the zero byte to 1
                fputc(byte, output_file_ptr);   //Write the byte with 1 set bit to the output file
            }
            else {
                byte = set_bit('\0', text_index%8);   //if it isn't, then set the text_index-th bit of the zero byte to 0
                fputc(byte, output_file_ptr);   //Write the byte with 0 set bit to the output file
            }
            ++text_index;
        }
    }
    fclose(output_file_ptr);
}

void steganography(char* command, char* input_file_name, char* output_file_name, char* message)
{
    //Checking if input file exists and can be opened
    FILE* input_file_ptr = fopen(input_file_name, "rb");
    if(input_file_ptr == NULL) {
        printf("Can not open %s file for reading.\n", input_file_name);
        return;
    }

    //Checking if output file can be created
    FILE* output_file_ptr = fopen(output_file_name, "wb");
    if(output_file_ptr == NULL) {
        printf("Can not create %s file.\n", output_file_name);
        fclose(input_file_ptr);
        return;
    }
    fclose(output_file_ptr);

    //Handling different subcommands
    if(strcasecmp(command, "-e") == 0) {    //If encode command is given
        encode(input_file_ptr, fopen(output_file_name, "wb"), message);
    }
    else if(strcasecmp(command, "-d") == 0) {   //If decode command is given
        decode(input_file_ptr, output_file_name);
    }
    else {
        printf("Invalid subcommand provided.\n");
    }
    fclose(input_file_ptr);
}

int main()
{
    char command[16], input_file_name[128], output_file_name[128], input_text[FILE_MAX_SIZE];
    printf("Command (\"-e\" for encoding, \"-d\" for decoding): ");
    fgets(command, 16, stdin);
    command[strlen(command)-1] = '\0';
    printf("Input file name: ");
    fgets(input_file_name, 128, stdin);
    input_file_name[strlen(input_file_name)-1] = '\0';
    printf("Output file name: ");
    fgets(output_file_name, 128, stdin);
    output_file_name[strlen(output_file_name)-1] = '\0';

    if(strcasecmp(command, "-e") == 0) {    //If encode command is given, take text to hide as input
        printf("Enter the text to be embedded: ");
        fgets(input_text, FILE_MAX_SIZE, stdin);
        input_text[strlen(input_text)-1] = '\0';
        steganography("-e", input_file_name, output_file_name, input_text);
    }
    else if(strcasecmp(command, "-d") == 0) {   //If decode command is given, no input text is needed
        steganography("-d", input_file_name, output_file_name, "");
    }
    return 0;
}