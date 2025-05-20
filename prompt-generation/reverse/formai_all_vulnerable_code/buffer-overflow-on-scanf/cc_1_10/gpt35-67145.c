//FormAI DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>

int main() {
    int option;
    float measurement, inch, feet, yard, mile;
    
    printf("Welcome to the Invasive Unit Converter!\n");
    
    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Convert from inches to feet, yards, and miles\n");
        printf("2. Convert from feet to inches, yards, and miles\n");
        printf("3. Convert from yards to inches, feet, and miles\n");
        printf("4. Convert from miles to inches, feet, and yards\n");
        printf("5. Exit\n");
        
        printf("Option: ");
        scanf("%d", &option);
        
        if (option == 5) {
            printf("\nThank you for using Invasive Unit Converter!\n");
            break;
        }
        
        printf("Enter measurement: ");
        scanf("%f", &measurement);
        
        switch (option) {
            case 1:
                inch = measurement;
                feet = inch / 12;
                yard = feet / 3;
                mile = yard / 1760;
                printf("%.2f inches is equal to:\n", inch);
                printf("%.2f feet\n", feet);
                printf("%.2f yards\n", yard);
                printf("%.5f miles\n", mile);
                break;
            case 2:
                feet = measurement;
                inch = feet * 12;
                yard = feet / 3;
                mile = yard / 1760;
                printf("%.2f feet is equal to:\n", feet);
                printf("%.2f inches\n", inch);
                printf("%.2f yards\n", yard);
                printf("%.5f miles\n", mile);
                break;
            case 3:
                yard = measurement;
                feet = yard * 3;
                inch = feet * 12;
                mile = yard / 1760;
                printf("%.2f yards is equal to:\n", yard);
                printf("%.2f feet\n", feet);
                printf("%.2f inches\n", inch);
                printf("%.5f miles\n", mile);
                break;
            case 4:
                mile = measurement;
                yard = mile * 1760;
                feet = yard * 3;
                inch = feet * 12;
                printf("%.5f miles is equal to:\n", mile);
                printf("%.2f yards\n", yard);
                printf("%.2f feet\n", feet);
                printf("%.2f inches\n", inch);
                break;
            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }
    }
    
    return 0;
}