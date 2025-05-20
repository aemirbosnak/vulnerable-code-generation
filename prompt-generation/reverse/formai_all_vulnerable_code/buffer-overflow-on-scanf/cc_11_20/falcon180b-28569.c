//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int decimal, binary[100], i, j;
    char choice;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Choose a binary system:\n");
    printf("1. Binary\n");
    printf("2. Octal\n");
    printf("3. Hexadecimal\n");
    scanf("%c", &choice);

    switch(choice) {
        case '1':
            printf("Binary: ");
            for(i=0; decimal>0; i++) {
                binary[i] = decimal%2;
                decimal /= 2;
            }
            for(j=i-1; j>=0; j--) {
                printf("%d", binary[j]);
            }
            break;
        case '2':
            printf("Octal: ");
            for(i=0; decimal>0; i++) {
                binary[i] = decimal%8;
                decimal /= 8;
            }
            for(j=i-1; j>=0; j--) {
                printf("%d", binary[j]);
            }
            break;
        case '3':
            printf("Hexadecimal: ");
            for(i=0; decimal>0; i++) {
                binary[i] = decimal%16;
                decimal /= 16;
            }
            for(j=i-1; j>=0; j--) {
                if(binary[j]<10) {
                    printf("%d", binary[j]);
                }
                else {
                    printf("%c", binary[j]+55);
                }
            }
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}