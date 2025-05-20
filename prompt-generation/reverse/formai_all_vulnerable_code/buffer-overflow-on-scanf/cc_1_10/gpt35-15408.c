//FormAI DATASET v1.0 Category: Digital Diary ; Style: interoperable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define FILENAME "digital_diary.txt"    // Name of the file


/* Function to encrypt the text using Caesar Cipher */
char* encryptText(char *text, int shift) {
    int length = strlen(text);
    char *encryptedText = malloc((length + 1) * sizeof(char));

    for(int i=0; i<length; i++) {
        if(isalpha(text[i])) {
            if(isupper(text[i]))
                encryptedText[i] = ((text[i] + shift - 'A') % 26) + 'A';
            else
                encryptedText[i] = ((text[i] + shift - 'a') % 26) + 'a';
        } else {
            encryptedText[i] = text[i];
        }
    }

    encryptedText[length] = '\0';  // Adding Null character at end of string
    return encryptedText;
}


/* Function to decrypt the text using Caesar Cipher */
char* decryptText(char *text, int shift) {
    int length = strlen(text);
    char *decryptedText = malloc((length + 1) * sizeof(char));

    for(int i=0; i<length; i++) {
        if(isalpha(text[i])) {
            if(isupper(text[i]))
                decryptedText[i] = ((text[i] - shift - 'A' + 26) % 26) + 'A';
            else
                decryptedText[i] = ((text[i] - shift - 'a' + 26) % 26) + 'a';
        } else {
            decryptedText[i] = text[i];
        }
    }

    decryptedText[length] = '\0';  // Adding Null character at end of string
    return decryptedText;
}


/* Function to get input from user */
void getInput(char *input) {
    int c, i=0;

    while((c = getchar()) != '\n' && c != EOF) {
        if(i < 1023) {
            input[i] = c;
            i++;
        }
    }

    input[i] = '\0';  // Adding Null character at end of string
}


int main() {
    FILE *fp;
    char input[1024], *textInFile, *encryptedText, *decryptedText;
    int shift;

    printf("*************************\n");
    printf("* Welcome to Digital Diary *\n");
    printf("*************************\n");

    /* Open the file in read mode */
    fp = fopen(FILENAME, "r");

    /* If file is present and not empty */
    if(fp != NULL) {
        fseek(fp, 0, SEEK_END);   // Move file pointer to end of file
        int fileSize = ftell(fp);   // Get the size of file
        fseek(fp, 0, SEEK_SET);   // Move file pointer to beginning of file

        /* Allocate memory for file content */
        textInFile = malloc((fileSize + 1) * sizeof(char));
        fread(textInFile, fileSize, 1, fp);   // Read entire file content into buffer
        textInFile[fileSize] = '\0';   // Adding Null character at end of string

        fclose(fp);   // Close the file
    } else {
        textInFile = malloc(sizeof(char));   // Allocate memory to hold '\0' character
        textInFile[0] = '\0';   // Adding Null character at end of string
    }

    printf("Your diary contains the following entries:\n\n%s\n", textInFile);

    while(1) {
        printf("\nEnter your choice:\n1. Add an entry\n2. Encrypt all entries\n3. Decrypt all entries\n4. Exit\n");
        int choice = getchar();
        getchar();   // Consume the newline which was not consumed by previous getchar() call

        switch(choice) {
            case '1':
                printf("Enter the text to add to your diary:\n");
                getInput(input);

                /* Append the new text to existing text */
                textInFile = realloc(textInFile, strlen(textInFile) + strlen(input) + 1);   // Reallocate memory for new text
                strcat(textInFile, input);

                printf("New text has been added to your diary!\n");
                break;

            case '2':
                printf("Enter the encryption key (0-25):\n");
                scanf("%d", &shift);
                getchar();   // Consume the newline which was not consumed by previous scanf() call

                encryptedText = encryptText(textInFile, shift);
                strcpy(textInFile, encryptedText);
                free(encryptedText);

                printf("Your diary has been encrypted!\n");
                break;

            case '3':
                printf("Enter the decryption key (0-25):\n");
                scanf("%d", &shift);
                getchar();   // Consume the newline which was not consumed by previous scanf() call

                decryptedText = decryptText(textInFile, shift);
                strcpy(textInFile, decryptedText);
                free(decryptedText);

                printf("Your diary has been decrypted!\n");
                break;

            case '4':
                /* Open the file in write mode */
                fp = fopen(FILENAME, "w");

                fwrite(textInFile, strlen(textInFile), 1, fp);   // Write the text to file
                fclose(fp);   // Close the file

                printf("Thank you for using Digital Diary. Have a nice day!\n");

                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}