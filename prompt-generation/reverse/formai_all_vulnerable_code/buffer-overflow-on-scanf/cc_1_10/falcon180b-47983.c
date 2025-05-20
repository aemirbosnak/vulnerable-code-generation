//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: scientific
#include <stdio.h>

// Function to count the number of set bits in an integer
int count_bits(int num) {
    int count = 0;
    while (num!= 0) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }
    return count;
}

// Function to reverse the bits of an integer
int reverse_bits(int num) {
    int rev = 0;
    while (num!= 0) {
        rev <<= 1;
        rev |= num & 1;
        num >>= 1;
    }
    return rev;
}

// Function to check if two integers have the same number of set bits
int same_bits(int num1, int num2) {
    int count1 = count_bits(num1);
    int count2 = count_bits(num2);
    return count1 == count2;
}

int main() {
    int num1, num2;

    // Get input from user
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Check if the two integers have the same number of set bits
    if (same_bits(num1, num2)) {
        printf("The two integers have the same number of set bits.\n");
    } else {
        printf("The two integers do not have the same number of set bits.\n");
    }

    // Reverse the bits of the first integer
    int rev1 = reverse_bits(num1);

    // Display the original integer and its reversed bits
    printf("Original integer: %d\n", num1);
    printf("Reversed bits: %d\n", rev1);

    return 0;
}