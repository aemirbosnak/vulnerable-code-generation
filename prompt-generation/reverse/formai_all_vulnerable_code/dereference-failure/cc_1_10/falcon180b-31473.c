//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: visionary
#include <stdio.h>

/* Function to reverse a string */
void reverse_string(char* str) {
    int len = strlen(str);
    char* start = str;
    char* end = str + len - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

/* Function to check if a number is a power of 2 */
int is_power_of_2(unsigned int n) {
    if (n == 0) {
        return 0;
    }
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}

/* Function to count the number of set bits in an integer */
int count_set_bits(unsigned int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

/* Function to check if a number is a palindrome */
int is_palindrome(unsigned int n) {
    char str[32];
    sprintf(str, "%u", n);
    reverse_string(str);
    return strcmp(str, "") == 0;
}

int main() {
    unsigned int num;
    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Is %u a power of 2? %s\n", num, is_power_of_2(num)? "Yes" : "No");
    printf("Number of set bits in %u: %d\n", num, count_set_bits(num));
    printf("Is %u a palindrome? %s\n", num, is_palindrome(num)? "Yes" : "No");

    return 0;
}