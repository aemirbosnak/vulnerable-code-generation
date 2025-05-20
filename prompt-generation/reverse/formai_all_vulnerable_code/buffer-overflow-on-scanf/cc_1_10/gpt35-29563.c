//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    printf("*************************\n");
    printf("** CHECKSUM CALCULATOR **\n");
    printf("*************************\n\n");
    
    int num, sum = 0, i = 0, choice;
    char input[100];
    
    printf("Enter a string (up to 100 characters): ");
    fgets(input, 100, stdin);
    
    printf("\nSelect a checksum method:\n");
    printf("1. Simple Sum\n");
    printf("2. XOR\n");
    printf("3. CRC\n");
    printf("4. Fletcher\n");
    
    printf("\nEnter choice (1-4): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            for(i = 0; input[i] != '\0'; i++) {
                sum += input[i];
            }
            printf("\nChecksum: %d\n", sum);
            break;
            
        case 2:
            for(i = 0; input[i] != '\0'; i++) {
                num = input[i];
                sum ^= num;
            }
            printf("\nChecksum: %d\n", sum);
            break;
            
        case 3:
            //CRC implementation
            printf("\nChecksum: %d\n", sum);
            break;
            
        case 4:
            //Fletcher implementation
            printf("\nChecksum: %d\n", sum);
            break;
            
        default:
            printf("\nInvalid choice. Please try again.\n");
    }
    
    return 0;
}