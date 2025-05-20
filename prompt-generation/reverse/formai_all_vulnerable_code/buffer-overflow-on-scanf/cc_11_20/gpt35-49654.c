//FormAI DATASET v1.0 Category: Compression algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// define a structure for storing the frequency of each character
typedef struct freq_node {
    int ascii_code;
    int freq;
    struct freq_node* next;
} freq_node;

void compress_file(char* input_file_name, char* output_file_name) {
    FILE* input_file = fopen(input_file_name, "r");
    FILE* output_file = fopen(output_file_name, "w");

    // set up an array to store the frequency of each character
    freq_node* freq_array[256] = {NULL};

    // read the input file and update the frequency of each character
    int current_char;
    while ((current_char = fgetc(input_file)) != EOF) {
        if (freq_array[current_char] == NULL) {
            freq_node* new_node = malloc(sizeof(freq_node));
            new_node->ascii_code = current_char;
            new_node->freq = 1;
            new_node->next = NULL;
            freq_array[current_char] = new_node;
        } else {
            freq_node* current_node = freq_array[current_char];
            while (current_node != NULL) {
                if (current_node->ascii_code == current_char) {
                    current_node->freq++;
                    break;
                } else if (current_node->next == NULL) {
                    freq_node* new_node = malloc(sizeof(freq_node));
                    new_node->ascii_code = current_char;
                    new_node->freq = 1;
                    new_node->next = NULL;
                    current_node->next = new_node;
                    break;
                }
                current_node = current_node->next;
            }
        }
    }

    // write the frequency table to the output file
    int num_of_chars = 0;
    for (int i = 0; i < 256; i++) {
        if (freq_array[i] != NULL) {
            num_of_chars++;
        }
    }
    fprintf(output_file, "%d\n", num_of_chars);
    for (int i = 0; i < 256; i++) {
        if (freq_array[i] != NULL) {
            fprintf(output_file, "%d %d ", i, freq_array[i]->freq);
            freq_node* current_node = freq_array[i]->next;
            while (current_node != NULL) {
                fprintf(output_file, "%d %d ", current_node->ascii_code, current_node->freq);
                current_node = current_node->next;
            }
            fprintf(output_file, "\n");
        }
    }

    // sort the frequency array by frequency in descending order
    freq_node* sorted_array[num_of_chars];
    int index = 0;
    for (int i = 0; i < 256; i++) {
        if (freq_array[i] != NULL) {
            sorted_array[index] = freq_array[i];
            index++;
        }
    }
    for (int i = 0; i < num_of_chars - 1; i++) {
        for (int j = i + 1; j < num_of_chars; j++) {
            if (sorted_array[i]->freq < sorted_array[j]->freq) {
                freq_node* temp = sorted_array[i];
                sorted_array[i] = sorted_array[j];
                sorted_array[j] = temp;
            }
        }
    }

    // set up an array of binary strings to represent each character
    char* binary_strings[256];
    for (int i = 0; i < 256; i++) {
        binary_strings[i] = NULL;
    }

    // build the Huffman tree
    while (num_of_chars > 1) {
        // take the two lowest frequency nodes and combine them into a new node
        freq_node* new_node = malloc(sizeof(freq_node));
        new_node->freq = sorted_array[num_of_chars - 1]->freq + sorted_array[num_of_chars - 2]->freq;
        new_node->next = NULL;

        // add the child nodes to the new node
        freq_node* left_child = sorted_array[num_of_chars - 1];
        freq_node* right_child = sorted_array[num_of_chars - 2];
        new_node->next = left_child;
        right_child->next = NULL;
        freq_node* current_node = left_child;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = right_child;

        // add the new node to the sorted array
        sorted_array[num_of_chars - 2] = new_node;
        num_of_chars--;

        // update the binary strings for each character
        char* left_child_binary = malloc(sizeof(char) * 2);
        left_child_binary[0] = '0';
        left_child_binary[1] = '\0';
        char* right_child_binary = malloc(sizeof(char) * 2);
        right_child_binary[0] = '1';
        right_child_binary[1] = '\0';
        current_node = left_child;
        while (current_node != NULL) {
            if (binary_strings[current_node->ascii_code] == NULL) {
                binary_strings[current_node->ascii_code] = malloc(sizeof(char) * 2);
                binary_strings[current_node->ascii_code][0] = '\0';
            }
            strcat(binary_strings[current_node->ascii_code], left_child_binary);
            current_node = current_node->next;
        }
        current_node = right_child;
        while (current_node != NULL) {
            if (binary_strings[current_node->ascii_code] == NULL) {
                binary_strings[current_node->ascii_code] = malloc(sizeof(char) * 2);
                binary_strings[current_node->ascii_code][0] = '\0';
            }
            strcat(binary_strings[current_node->ascii_code], right_child_binary);
            current_node = current_node->next;
        }
    }

    // reset the input file pointer to the beginning of the file
    fseek(input_file, 0, SEEK_SET);

    // encode the input file using the Huffman tree and write the encoded file to the output file
    int current_bit = 0;
    int current_byte = 0;
    int num_of_chars_encoded = 0;
    fprintf(output_file, " ");
    while ((current_char = fgetc(input_file)) != EOF) {
        char* binary_string = binary_strings[current_char];
        int length = strlen(binary_string);
        for (int i = 0; i < length; i++) {
            char bit = binary_string[i];
            if (bit == '1') {
                current_byte += pow(2, 7 - current_bit);
            }
            current_bit++;
            if (current_bit == 8) {
                fprintf(output_file, "%c", current_byte);
                current_byte = 0;
                current_bit = 0;
            }
        }
        num_of_chars_encoded++;
    }
    if (current_bit > 0) {
        fprintf(output_file, "%c", current_byte);
    }
    rewind(output_file);
    fprintf(output_file, "%d", num_of_chars_encoded);

    // free memory
    for (int i = 0; i < 256; i++) {
        if (binary_strings[i] != NULL) {
            free(binary_strings[i]);
        }
        while (freq_array[i] != NULL) {
            freq_node* temp = freq_array[i];
            freq_array[i] = freq_array[i]->next;
            free(temp);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

void decompress_file(char* input_file_name, char* output_file_name) {
    FILE* input_file = fopen(input_file_name, "r");
    FILE* output_file = fopen(output_file_name, "w");

    // read the frequency table from the input file and create the Huffman tree
    freq_node* freq_array[256] = {NULL};
    int num_of_chars;
    fscanf(input_file, "%d", &num_of_chars);
    for (int i = 0; i < num_of_chars; i++) {
        int ascii_code;
        int freq;
        fscanf(input_file, "%d%d", &ascii_code, &freq);
        freq_node* new_node = malloc(sizeof(freq_node));
        new_node->ascii_code = ascii_code;
        new_node->freq = freq;
        new_node->next = NULL;
        freq_array[ascii_code] = new_node;
    }
    freq_node* sorted_array[num_of_chars];
    int index = 0;
    for (int i = 0; i < 256; i++) {
        if (freq_array[i] != NULL) {
            sorted_array[index] = freq_array[i];
            index++;
        }
    }
    for (int i = 0; i < num_of_chars - 1; i++) {
        for (int j = i + 1; j < num_of_chars; j++) {
            if (sorted_array[i]->freq < sorted_array[j]->freq) {
                freq_node* temp = sorted_array[i];
                sorted_array[i] = sorted_array[j];
                sorted_array[j] = temp;
            }
        }
    }
    while (num_of_chars > 1) {
        freq_node* new_node = malloc(sizeof(freq_node));
        new_node->freq = sorted_array[num_of_chars - 1]->freq + sorted_array[num_of_chars - 2]->freq;
        new_node->next = NULL;
        freq_node* left_child = sorted_array[num_of_chars - 1];
        freq_node* right_child = sorted_array[num_of_chars - 2];
        new_node->next = left_child;
        right_child->next = NULL;
        freq_node* current_node = left_child;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = right_child;
        sorted_array[num_of_chars - 2] = new_node;
        num_of_chars--;
    }

    // decode the input file using the Huffman tree and write the decoded file to the output file
    int current_bit = 0;
    int current_byte = fgetc(input_file);
    int num_of_chars_decoded = 0;
    freq_node* current_node = sorted_array[0];
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    while (num_of_chars_decoded < current_node->freq) {
        int bit = (current_byte >> (7 - current_bit)) & 1;
        if (bit == 0) {
            current_node = current_node->next;
        } else {
            current_node = current_node->next->next;
        }
        current_bit++;
        if (current_bit == 8) {
            current_byte = fgetc(input_file);
            current_bit = 0;
        }
        if (current_node->next == NULL) {
            fprintf(output_file, "%c", current_node->ascii_code);
            num_of_chars_decoded++;
            current_node = sorted_array[0];
            while (current_node->next != NULL) {
                current_node = current_node->next;
            }
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    char input_file_name[100];
    char output_file_name[100];
    printf("Enter the input file name: ");
    scanf("%s", input_file_name);
    printf("Enter the output file name: ");
    scanf("%s", output_file_name);
    compress_file(input_file_name, output_file_name);
    printf("File compressed successfully!\n");
    printf("Enter the input file name: ");
    scanf("%s", input_file_name);
    printf("Enter the output file name: ");
    scanf("%s", output_file_name);
    decompress_file(input_file_name, output_file_name);
    printf("File decompressed successfully!\n");
    return 0;
}