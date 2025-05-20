//FormAI DATASET v1.0 Category: Audio processing ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    int length, choice;

    printf("Welcome to the Voice Modulator!\nPlease enter your input: ");
    fgets(input, sizeof(input), stdin);
    length = strlen(input);
    input[length - 1] = '\0'; // remove newline character

    printf("\nChoose an effect:\n1. Robot\n2. Alien\n3. Echo\n4. Reverse\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Robot effect
            for(int i=0; i<length; i++) {
                if(input[i] == ' ') {
                    printf(" ");
                } else {
                    printf("%c%d", input[i], rand()%10);
                }
            }
            break;

        case 2: // Alien effect
            for(int i=0; i<length; i++) {
                if(input[i] == ' ') {
                    printf(" ");
                } else {
                    printf("%c*", input[i]+3);
                }
            }
            break;

        case 3: // Echo effect
            for(int i=0; i<length; i++) {
                printf("%c", input[i]);
                if(input[i] != ' ') {
                    for(int j=0; j<5; j++) {
                        printf("%c", input[i]);
                    }
                }
            }
            break;

        case 4: // Reverse effect
            for(int i=length-1; i>=0; i--) {
                printf("%c", input[i]);
            }
            break;

        default: // Invalid choice
            printf("\nInvalid choice!");
    }

    printf("\n\nThank you for using the Voice Modulator!\n");

    return 0;
}