//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    char word[MAX_WORD_LEN];
    int word_count = 0;
    
    while (fscanf(file, "%s", word)!= EOF) {
        word_count++;
        char *token = strtok(word, " \t\n\r");
        while (token!= NULL) {
            if (strlen(token) > 0 && isalpha(token[0])) {
                token[strlen(token) - 1] = '\0';
                int count = 1;
                char *ptr = token;
                while (ptr!= NULL && *ptr!= '\0') {
                    ptr++;
                    count++;
                }
                if (count > 1) {
                    char *new_word = (char*)malloc(count * sizeof(char));
                    strcpy(new_word, token);
                    word_count += count;
                    int i = 0;
                    while (ptr!= NULL && *ptr!= '\0') {
                        new_word[i] = *ptr;
                        ptr++;
                        i++;
                    }
                    new_word[i] = '\0';
                    printf("%s\t%d\n", new_word, count);
                }
            }
            token = strtok(NULL, " \t\n\r");
        }
    }
    
    fclose(file);
    printf("Total word count: %d\n", word_count);
    return 0;
}