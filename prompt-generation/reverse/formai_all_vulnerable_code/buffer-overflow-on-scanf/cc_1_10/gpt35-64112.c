//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initializing variables
    int data[8];
    int sum = 0;

    // Getting input from user
    printf("Enter 8 bits of data:\n");
    for(int i=0; i<8; i++){
        scanf("%d", &data[i]);
        // Checking if entered bit is 0 or 1
        if(data[i]!=0 && data[i]!=1){
            printf("Invalid input! Please enter binary bits only.\n");
            exit(0);
        }
    }

    // Calculating checksum
    printf("\nCalculating checksum...\n");
    for (int i = 0; i < 8; i++) {
        sum += data[i];
    }

    // Adding carry to the sum
    while (sum > 1) {
        int carry = sum / 2;
        if (sum % 2 == 0) {
            sum = carry;
        } else {
            sum = carry + 1;
        }
    }

    // Displaying checksum value
    printf("Checksum value: %d\n",sum);

    // Inverting bits of the input data
    printf("\nInverting bits of the input data...\n");
    for (int i = 0; i < 8; i++) {
        if(data[i] == 0){
            data[i] = 1;
        }else{
            data[i] = 0;
        }
        printf("%d ", data[i]);
    }

    // Displaying final message with checksum appended to the data
    printf("\n\nData with checksum appended: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", data[i]);
    }
    printf("%d\n", sum);

    return 0;
}