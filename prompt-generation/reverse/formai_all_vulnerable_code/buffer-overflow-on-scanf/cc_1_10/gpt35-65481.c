//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

int main()
{
    char filename[100], word[MAX_LENGTH], new_word[MAX_LENGTH];
    int pos, choice;

    printf("Enter the filename: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0; // remove newline character

    FILE *fp = fopen(filename, "r+"); // open file in read-write mode

    if(fp == NULL){
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter the word to search for: ");
    fgets(word, MAX_LENGTH, stdin);
    word[strcspn(word, "\n")] = 0;

    printf("Enter the position of the word to replace (starting from 0): ");
    scanf("%d", &pos);

    printf("Enter the new word: ");
    scanf("%s", new_word);

    // move file pointer to the appropriate position
    fseek(fp, pos*(MAX_LENGTH+1), SEEK_SET);

    // read the word from file
    fread(word, MAX_LENGTH, 1, fp);

    if(feof(fp)){ // check if end of file reached prematurely
        printf("Error reading file.\n");
        exit(1);
    }

    if(strcmp(word, new_word) == 0){ // check if new word is same as old word
        printf("New word is same as old word. Exiting...\n");
        exit(1);
    }

    // move file pointer back to the position of the old word
    fseek(fp, -MAX_LENGTH, SEEK_CUR);

    // write the new word to file
    fwrite(new_word, MAX_LENGTH, 1, fp);

    if(ferror(fp)){ // check if any errors occurred while writing to file
        printf("Error writing to file.\n");
        exit(1);
    }

    printf("Word replaced successfully!\n");

    fclose(fp); // close the file
    return 0;
}