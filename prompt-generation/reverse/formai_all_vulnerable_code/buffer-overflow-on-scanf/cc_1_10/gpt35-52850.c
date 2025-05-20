//FormAI DATASET v1.0 Category: Image Steganography ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME 100

// The following function takes a file name and returns a pointer to an allocated array of bytes read from that file.
unsigned char* read_file(const char* file_name, size_t* length_ptr) {
    FILE* fp = fopen(file_name, "rb");
    fseek(fp, 0, SEEK_END);
    size_t length = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    unsigned char* buffer = (unsigned char*)malloc(length);
    fread(buffer, length, 1, fp);
    fclose(fp);
    *length_ptr = length;
    return buffer;
}

// The following function takes a pointer to an array of bytes, the number of bytes to hide, and the number of bits to hide each byte in,
// and returns a pointer to an allocated array of bytes with the hidden data.
unsigned char* hide_data(unsigned char* source, size_t length_in_bytes, const char* data_to_hide, size_t length_to_hide, int bits_per_byte) {
    if (length_in_bytes * bits_per_byte < length_to_hide * 8) {
        printf("Not enough space to hide data.\n");
        return NULL;
    }
    unsigned char* hidden_data = (unsigned char*)malloc(length_in_bytes);
    size_t byte_index = 0;
    size_t bit_index = 0;
    for (size_t i = 0; i < length_to_hide; i++) {
        char current_char = data_to_hide[i];
        for (int j = 0; j < 8; j++) {
            // Clear the appropriate bit in the current byte
            hidden_data[byte_index] &= ~(1 << bit_index);
            // Set the bit according to the current character
            if ((current_char & (1 << j)) != 0) {
                hidden_data[byte_index] |= (1 << bit_index);
            }
            bit_index += bits_per_byte;
            if (bit_index >= 8) {
                byte_index += 1;
                bit_index = 0;
            }
        }
    }
    return hidden_data;
}

// The following function takes a pointer to an array of bytes with hidden data, the number of bytes, and the number of bits to extract,
// and returns a pointer to an allocated array of bytes with the extracted data.
unsigned char* extract_data(unsigned char* hidden_data, size_t length_in_bytes, size_t length_to_extract, int bits_per_byte) {
    unsigned char* extracted_data = (unsigned char*)malloc(length_to_extract);
    size_t byte_index = 0;
    size_t bit_index = 0;
    for (size_t i = 0; i < length_to_extract; i++) {
        char current_char = 0;
        for (int j = 0; j < 8; j++) {
            if ((bit_index % bits_per_byte) == 0) {
                current_char = 0;
            }
            // Extract the current bit from the appropriate byte
            if ((hidden_data[byte_index] & (1 << bit_index)) != 0) {
                current_char |= (1 << (j % 8));
            }
            bit_index += 1;
            if (bit_index >= 8) {
                byte_index += 1;
                bit_index = 0;
            }
        }
        extracted_data[i] = current_char;
    }
    return extracted_data;
}

int main() {
    // Read the source image file and the file with the data to hide
    char source_file_name[MAX_FILE_NAME];
    printf("Enter source file name: ");
    scanf("%s", source_file_name);
    size_t source_length = 0;
    unsigned char* source_data = read_file(source_file_name, &source_length);
    if (!source_data) {
        printf("Error reading source file.\n");
        return 1;
    }

    char data_to_hide_file_name[MAX_FILE_NAME];
    printf("Enter file name with data to hide: ");
    scanf("%s", data_to_hide_file_name);
    size_t data_to_hide_length = 0;
    unsigned char* data_to_hide = read_file(data_to_hide_file_name, &data_to_hide_length);
    if (!data_to_hide) {
        printf("Error reading data to hide file.\n");
        return 1;
    }

    // Hide the data in the source image
    int bits_per_byte = 2;
    unsigned char* steganographic_data = hide_data(source_data, source_length, data_to_hide, data_to_hide_length, bits_per_byte);
    if (!steganographic_data) {
        return 1;
    }

    // Write the steganographic image to a file
    char steganographic_file_name[MAX_FILE_NAME];
    printf("Enter steganographic file name: ");
    scanf("%s", steganographic_file_name);
    FILE* fp = fopen(steganographic_file_name, "wb");
    fwrite(steganographic_data, source_length, 1, fp);
    fclose(fp);

    // Extract the hidden data from the steganographic image and write it to a file
    unsigned char* extracted_data = extract_data(steganographic_data, source_length, data_to_hide_length, bits_per_byte);
    if (!extracted_data) {
        return 1;
    }
    char extracted_data_file_name[MAX_FILE_NAME];
    printf("Enter extracted data file name: ");
    scanf("%s", extracted_data_file_name);
    fp = fopen(extracted_data_file_name, "wb");
    fwrite(extracted_data, data_to_hide_length, 1, fp);
    fclose(fp);

    // Free memory
    free(source_data);
    free(data_to_hide);
    free(steganographic_data);
    free(extracted_data);

    return 0;
}