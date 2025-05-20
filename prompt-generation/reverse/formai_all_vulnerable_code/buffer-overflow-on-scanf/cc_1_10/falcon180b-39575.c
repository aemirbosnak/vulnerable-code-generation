//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove punctuation from a string
void removePunctuation(char* str) {
    int i, j;
    for(i=0, j=0; str[i]!='\0'; i++) {
        if(!isalnum(str[i])) {
            continue;
        }
        str[j++] = tolower(str[i]);
    }
    str[j] = '\0';
}

// Function to count the frequency of each word in a string
void countWords(char* str, int* freq) {
    int i, j;
    char word[100];
    for(i=0, j=0; str[i]!='\0'; i++) {
        if(str[i]==' ') {
            word[j] = '\0';
            freq[(int)hash(word)]++;
            j = 0;
        }
        else {
            word[j++] = tolower(str[i]);
        }
    }
    word[j] = '\0';
    freq[(int)hash(word)]++;
}

// Function to generate a hash value for a string
int hash(char* str) {
    int hash = 0;
    while(*str) {
        hash += *str++;
    }
    return hash % 100;
}

// Function to print the top N words with their frequencies
void printTopWords(int* freq, int N) {
    int i;
    for(i=0; i<100; i++) {
        if(freq[i]!=0) {
            printf("%s: %d\n", &"ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i*3], freq[i]);
            if(--N==0) {
                break;
            }
        }
    }
}

// Main function
int main() {
    FILE* fp;
    char line[1000];
    char text[10000];
    int freq[26];
    int N;

    printf("Enter the name of the input file: ");
    scanf("%s", line);

    fp = fopen(line, "r");
    if(fp==NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("Enter the number of top words to display: ");
    scanf("%d", &N);

    while(fgets(line, sizeof(line), fp)!=NULL) {
        strcat(text, line);
    }

    fclose(fp);

    removePunctuation(text);

    countWords(text, freq);

    printTopWords(freq, N);

    return 0;
}