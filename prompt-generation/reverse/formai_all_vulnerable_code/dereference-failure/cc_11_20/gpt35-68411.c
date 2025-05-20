//FormAI DATASET v1.0 Category: Data recovery tool ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFF_SIZE 1024

typedef struct {
    char **strings;
    int *lengths;
    int num_strings;
} string_array_t;

int main() {
    FILE *file_ptr;
    char buffer[BUFF_SIZE];
    string_array_t lines;
    lines.num_strings = 0;

    // Check if data recovery input file can be opened for reading
    if ((file_ptr = fopen("data_recovery.txt", "r")) == NULL) {
        printf("Error opening data_recovery.txt file\n");
        return 1;
    }

    // Read lines from the input file
    while (fgets(buffer, BUFF_SIZE, file_ptr)) {
        int buffer_length = (int) strlen(buffer);

        // Add line to the string array
        lines.strings = (char **) realloc(lines.strings, sizeof(char *) * (lines.num_strings + 1));
        lines.lengths = (int *) realloc(lines.lengths, sizeof(int) * (lines.num_strings + 1));
        lines.strings[lines.num_strings] = (char *) malloc(buffer_length + 1);
        strncpy(lines.strings[lines.num_strings], buffer, buffer_length);
        lines.strings[lines.num_strings][buffer_length] = '\0';
        lines.lengths[lines.num_strings] = buffer_length;
        lines.num_strings++;
    }

    // Close input file
    fclose(file_ptr);

    // Check if any lines were read in
    if (lines.num_strings == 0) {
        printf("No lines found in input file\n");
        return 1;
    }

    // Reorder lines based on recovery indices
    for (int i = 0; i < lines.num_strings - 1; i++) {
        for (int j = i; j < lines.num_strings; j++) {
            int i_index, j_index;
            if (sscanf(lines.strings[i], "%d", &i_index) != 1) {
                i_index = -1;
            }
            if (sscanf(lines.strings[j], "%d", &j_index) != 1) {
                j_index = -1;
            }
            if (i_index >= 1 && i_index <= lines.num_strings &&
                j_index >= 1 && j_index <= lines.num_strings &&
                i_index > j_index) {
                char *temp_string = lines.strings[i];
                int temp_length = lines.lengths[i];
                lines.strings[i] = lines.strings[j];
                lines.lengths[i] = lines.lengths[j];
                lines.strings[j] = temp_string;
                lines.lengths[j] = temp_length;
            }
        }
    }

    // Print out reordered lines
    for (int i = 0; i < lines.num_strings; i++) {
        fwrite(lines.strings[i], sizeof(char), lines.lengths[i], stdout);
    }

    // Free memory allocated for string array
    for (int i = 0; i < lines.num_strings; i++) {
        free(lines.strings[i]);
    }
    free(lines.strings);
    free(lines.lengths);

    return 0;
}