//FormAI DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int len = strlen(str);
    char temp;
    for(int i=0; i<len/2; i++) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

void encodeString(char str[], int key) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        str[i] = str[i] + key;
    }
}

void decodeString(char str[], int key) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        str[i] = str[i] - key;
    }
}

int main() {
    char str[100];
    int choice, key;
    do {
        printf("Enter a string to process: ");
        fgets(str, 100, stdin);
        printf("\n");
        printf("Choose an option: \n");
        printf("1. Reverse the string.\n");
        printf("2. Encode the string.\n");
        printf("3. Decode the string.\n");
        printf("4. Exit.\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                reverseString(str);
                printf("Reversed string: %s\n", str);
                break;
            case 2:
                printf("Enter the key to encode the string: ");
                scanf("%d", &key);
                encodeString(str, key);
                printf("Encoded string: %s\n", str);
                break;
            case 3:
                printf("Enter the key to decode the string: ");
                scanf("%d", &key);
                decodeString(str, key);
                printf("Decoded string: %s\n", str);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
        getchar(); // to clear the input buffer
        printf("Press Enter to continue...");
        getchar(); // to wait for user input before continuing
        printf("\n");
    } while(choice != 4);
    return 0;
}