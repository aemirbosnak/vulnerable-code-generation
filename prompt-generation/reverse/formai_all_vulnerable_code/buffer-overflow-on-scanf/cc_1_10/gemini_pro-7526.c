//GEMINI-pro DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Let's play a game of "Would You Rather?" with files!

    // I present you with two files: "file1.txt" and "file2.txt".
    // Which one would you rather have a peek into?

    printf("Enter '1' for file1.txt or '2' for file2.txt: ");
    int choice;
    scanf("%d", &choice);

    // Okay, you're curious about file1.txt. Good choice!
    if (choice == 1) {
        // Let's open the file for reading.
        FILE *file1 = fopen("file1.txt", "r");

        // Oh no! The file doesn't seem to exist.
        if (file1 == NULL) {
            printf("Oops, file1.txt doesn't exist! Try the other one.\n");
            return 1;
        }

        // Phew, the file exists! Let's read it character by character.
        char c;
        while ((c = fgetc(file1)) != EOF) {
            printf("%c", c);
        }

        // We're done reading, so let's close the file.
        fclose(file1);
    }
    // You're more interested in file2.txt? No problem!
    else if (choice == 2) {
        // Let's try opening file2.txt instead.
        FILE *file2 = fopen("file2.txt", "w");

        // Hang on, you want to write to file2.txt? Sure thing!
        char text[100];
        printf("Type some text to write to file2.txt: ");
        scanf(" %[^\n]%*c", text);

        // We're writing to the file now.
        fprintf(file2, "%s", text);

        // We're done writing, so let's close the file.
        fclose(file2);
    }
    // Oops, you didn't choose either file. Try again!
    else {
        printf("Invalid choice. Please enter '1' or '2'.\n");
        return 1;
    }

    printf("\nWould you like to play again? ");
    char answer;
    scanf(" %c", &answer);

    // You want to play again? Let's go!
    if (answer == 'y' || answer == 'Y') {
        main();
    }
    // Okay, thanks for playing!
    else {
        printf("Goodbye!\n");
    }

    return 0;
}