//FormAI DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the Ephemeral Unit Converter!\n");
    printf("This converter can convert between ephemeral units such as dreams, emotions, and memories.\n");

    int choice;
    float input;
    float result;

    while(1) {

        printf("\nWhat would you like to convert?\n");
        printf("1. Dreams to Memories\n");
        printf("2. Emotions to Dreams\n");
        printf("3. Memories to Emotions\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter number of Dreams: ");
                scanf("%f", &input);
                result = input * 0.7;
                printf("%.2f Dreams is equal to %.2f Memories\n", input, result);
                break;
            case 2:
                printf("Enter number of Emotions: ");
                scanf("%f", &input);
                result = input * 1.5;
                printf("%.2f Emotions is equal to %.2f Dreams\n", input, result);
                break;
            case 3:
                printf("Enter number of Memories: ");
                scanf("%f", &input);
                result = input * 2.0;
                printf("%.2f Memories is equal to %.2f Emotions\n", input, result);
                break;
            case 4:
                printf("Thank you for using the Ephemeral Unit Converter!\n");
                exit(0);
            default:
                printf("Invalid input! Please enter a number between 1 and 4.\n");
        }

    }

    return 0;

}