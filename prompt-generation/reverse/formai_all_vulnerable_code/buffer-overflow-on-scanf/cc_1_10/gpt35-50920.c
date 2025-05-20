//FormAI DATASET v1.0 Category: Text processing ; Style: expert-level
#include<stdio.h>

//function to convert text to Ascii Code
void text_to_ascii(char *text) {
    int i=0;
    while (text[i] != '\0') {
        printf("%d ", text[i]); //print ascii code
        i++;
    }
    printf("\n");
}

//function to convert ascii code to text
void ascii_to_text(int code[]) {
    int i=0;
    while (code[i] != -1) {
        printf("%c", code[i]); //print character corresponding to ascii code
        i++;
    }
    printf("\n");
}

int main() {
    char text[100];
    int code[100];
    int choice, i;

    while(1) {
        printf("1. Convert text to ASCII code\n");
        printf("2. Convert ASCII code to text\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter text: ");
                scanf(" %[^\n]", text); //read entire line
                text_to_ascii(text);
                break;
            case 2:
                i=0;
                printf("Enter ASCII codes (-1 to stop): ");
                while (1) {
                    scanf("%d", &code[i]);
                    if (code[i] == -1) {
                        break;
                    }
                    i++;
                }
                ascii_to_text(code);
                break;
            case 3:
                printf("Exiting program...");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}