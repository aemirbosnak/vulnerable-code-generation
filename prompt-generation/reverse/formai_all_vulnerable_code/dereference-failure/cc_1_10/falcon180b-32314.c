//Falcon-180B DATASET v1.0 Category: Text processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE_LENGTH 512
#define MAX_WORD_LENGTH 64

// Function prototypes
void generate_random_string(char* str, int length);
int is_palindrome(char* str);

int main(int argc, char* argv[]) {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        int num_words = 0;
        char* words[MAX_LINE_LENGTH / MAX_WORD_LENGTH];
        char* token = strtok(line, " ");
        while (token!= NULL) {
            if (num_words >= MAX_LINE_LENGTH / MAX_WORD_LENGTH) {
                break;
            }
            strcpy(words[num_words], token);
            num_words++;
            token = strtok(NULL, " ");
        }

        for (int i = 0; i < num_words; i++) {
            generate_random_string(words[i], strlen(words[i]));
        }

        printf("%s", line);
        for (int i = 0; i < num_words; i++) {
            printf(" %s", words[i]);
        }
        printf("\n");
    }

    fclose(input_file);
    return 0;
}

void generate_random_string(char* str, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[length] = '\0';
}

int is_palindrome(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i])!= tolower(str[length - i - 1])) {
            return 0;
        }
    }
    return 1;
}