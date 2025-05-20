//FormAI DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[1000];
    int count = 0;

    // Ask user to enter some text
    printf("Please enter some text:\n");
    fgets(text, 1000, stdin);

    // Count the number of words in the text
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            count++;
        }
    }
    count++; // add 1 to account for the last word

    // Print the number of words and ask if user wants to replace any of them
    printf("Your text contains %d words.\n", count);
    printf("Do you want to replace any words? (y/n): ");
    char choice = getchar();

    // If user wants to replace a word, ask for the word and replacement
    if (choice == 'y') {
        int num;
        char word[20], replacement[20];
        printf("Which word do you want to replace? (enter the number): ");
        scanf("%d", &num);
        printf("Enter the word you want to replace it with: ");
        scanf("%s", replacement);

        // Split the text into words and replace the selected word
        char* token = strtok(text, " ");
        int i = 1;
        while (token != NULL) {
            if (i == num) {
                strcpy(word, token);
                token = replacement;
            }
            printf("%s ", token);
            token = strtok(NULL, " ");
            i++;
        }
        printf("\n");

        // Ask user if they want to save the modified text to a file
        printf("Do you want to save the modified text to a file? (y/n): ");
        char choice2 = getchar();

        // If user wants to save the file, ask for the filename and write to it
        if (choice2 == 'y') {
            FILE* fp;
            char filename[20];
            printf("Enter the filename: ");
            scanf("%s", filename);
            fp = fopen(filename, "w");
            fprintf(fp, "%s", text);
            fclose(fp);
            printf("File saved!\n");
        }
    }
    return 0;
}