//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: intelligent
#include <stdio.h>

// Function to count the number of set bits in an integer
int count_bits(unsigned int n) {
    int count = 0;
    while(n) {
        count++;
        n &= (n - 1);
    }
    return count;
}

int main() {
    unsigned int num;
    printf("Enter an integer: ");
    scanf("%u", &num);

    // Count the number of set bits in the input integer
    int bits_count = count_bits(num);

    // Check if the input integer is a power of two
    if(num &&!(num & (num - 1))) {
        printf("%u is a power of two.\n", num);
    } else {
        printf("%u is not a power of two.\n", num);
    }

    // Check if the input integer is a palindrome
    char str[33];
    sprintf(str, "%u", num);
    int len = strlen(str);
    for(int i = 0; i < len/2; i++) {
        if(str[i]!= str[len - i - 1]) {
            printf("%u is not a palindrome.\n", num);
            break;
        }
    }

    // Check if the input integer is a perfect number
    int sum = 0;
    for(int i = 1; i <= num/2; i++) {
        if(num % i == 0) {
            sum += i;
        }
    }
    if(sum == num) {
        printf("%u is a perfect number.\n", num);
    } else {
        printf("%u is not a perfect number.\n", num);
    }

    return 0;
}