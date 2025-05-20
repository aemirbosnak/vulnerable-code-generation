//Falcon-180B DATASET v1.0 Category: Data mining ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function to calculate the frequency of each word in a text file
void wordFrequency(char* filename, char* wordlist[], int num_words) {
    FILE* fp;
    char ch;
    int i = 0, j = 0;
    char word[100];
    int freq[26] = {0};

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            word[i++] = toupper(ch);
        } else {
            if (i > 0) {
                word[i] = '\0';
                for (j = 0; j < num_words; j++) {
                    if (strcmp(word, wordlist[j]) == 0) {
                        freq[j]++;
                        break;
                    }
                }
                i = 0;
            }
        }
    }

    if (i > 0) {
        word[i] = '\0';
        for (j = 0; j < num_words; j++) {
            if (strcmp(word, wordlist[j]) == 0) {
                freq[j]++;
                break;
            }
        }
    }

    fclose(fp);

    printf("Word\tFrequency\n");
    for (j = 0; j < num_words; j++) {
        printf("%s\t%d\n", wordlist[j], freq[j]);
    }
}

int main() {
    char filename[100];
    char wordlist[100][100];
    int num_words = 0;

    // Prompt user for filename and words to search for
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter words to search for (separated by space): ");
    scanf("%s", wordlist[num_words]);
    while (strcmp(wordlist[num_words], "")!= 0) {
        num_words++;
        printf("Enter words to search for (separated by space): ");
        scanf("%s", wordlist[num_words]);
    }

    // Calculate word frequency
    wordFrequency(filename, wordlist, num_words);

    return 0;
}