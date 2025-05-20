//FormAI DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main(){

    // Introductory Text
    printf("Welcome to the Post-Apocalyptic World!\n\n");

    // File Handling
    FILE *fptr;
    char filename[20];
    char word[20];
    int count = 0;
    int i, j;

    // Initializing the filename
    printf("Please enter the name of the file you want to create: ");
    fgets(filename, 20, stdin);

    // Replacing the '\n' at the end of the filename string with '\0'
    for (i = 0; filename[i] != '\n'; i++);
    filename[i] = '\0';

    // Opening the file
    fptr = fopen(filename, "w");

    // Checking if the file is successfully opened
    if (fptr == NULL){
        printf("Error: File cannot be opened.\n");
        exit(0);
    }

    // Writing into the file
    printf("\nPlease enter the words you want to save:\n");

    for (i = 0; i < 5; i++){
        printf("Word %d: ", i + 1);
        fgets(word, 20, stdin);
        fprintf(fptr,"%s", word);
    }

    // Closing the file
    fclose(fptr);
    
    // Counting the number of words with at least one vowel
    fptr = fopen(filename, "r");

    if (fptr == NULL){
        printf("Error: File cannot be opened.\n");
        exit(0);
    }

    while ((j = fgetc(fptr)) != EOF){
        if (j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u' || j == 'A' || j == 'E' || j == 'I' || j == 'O' || j == 'U'){
            count++;
        }
    }

    // Closing the file
    fclose(fptr);

    // Displaying the count
    printf("\nNumber of words with at least one vowel in the '%s' file: %d\n", filename, count);

    return 0;
}