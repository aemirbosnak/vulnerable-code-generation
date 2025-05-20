//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: grateful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_NAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    char file_name[MAX_FILE_NAME_LENGTH] = "";
    FILE *file;
    char line[MAX_LINE_LENGTH] = "";
    char word[MAX_WORD_LENGTH] = "";
    int word_count = 0;
    int letter_count = 0;
    int line_count = 0;
    int total_word_count = 0;
    int total_letter_count = 0;
    int total_line_count = 0;
    int total_files_count = 0;

    printf("Enter the file name: ");
    scanf("%s", file_name);

    file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        return 0;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_count++;

        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            strcpy(word, token);
            total_word_count++;
            word_count++;

            if (strlen(word) > MAX_WORD_LENGTH) {
                printf("Error: Word too long.\n");
                return 0;
            }

            if (isalpha(word[0])) {
                letter_count = strlen(word);
                total_letter_count += letter_count;
            }

            total_files_count += 1;

            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    printf("Total word count: %d\n", total_word_count);
    printf("Total letter count: %d\n", total_letter_count);
    printf("Total line count: %d\n", total_line_count);
    printf("Total files count: %d\n", total_files_count);

    return 0;
}