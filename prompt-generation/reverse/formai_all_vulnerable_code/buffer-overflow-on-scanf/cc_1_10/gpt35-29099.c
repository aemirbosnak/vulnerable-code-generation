//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
    char inputString[1000], watermarkString[100];
    int choice, len, i, j;
    printf("Welcome to C Digital Watermarking Example Program!\n\n");
    printf("Please choose from the following options:\n\n");
    printf("1. Add Watermark\n");
    printf("2. Remove Watermark\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\n\nEnter the text you want to add watermark to: ");
            getchar();
            fgets(inputString, 1000, stdin);
            len = strlen(inputString);
            printf("\nEnter the watermark text: ");
            fgets(watermarkString, 100, stdin);
            for(i = len - 1, j = strlen(watermarkString) - 1; j >= 0; i--, j--) {
                inputString[i] = watermarkString[j];
            }
            inputString[len] = '\0';
            printf("\nText with watermark: %s", inputString);
            break;
        case 2:
            printf("\n\nEnter the text with watermark to remove: ");
            getchar();
            fgets(inputString, 1000, stdin);
            printf("\nEnter the watermark text to remove: ");
            fgets(watermarkString, 100, stdin);
            len = strlen(inputString);
            int watermarkLen = strlen(watermarkString);
            for(i = len - 1; i >= 0; i--) {
                if(inputString[i] == watermarkString[watermarkLen-1]) {
                    int flag = 1;
                    for(j = 0; j < watermarkLen; j++) {
                        if(inputString[i-j] != watermarkString[watermarkLen-j-1]) {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag) {
                        inputString[i+1-watermarkLen] = '\0';
                        break;
                    }
                }
            }
            printf("\nText with watermark removed: %s", inputString);
            break;
        default:
            printf("\nInvalid choice!");
    }
    return 0;
}