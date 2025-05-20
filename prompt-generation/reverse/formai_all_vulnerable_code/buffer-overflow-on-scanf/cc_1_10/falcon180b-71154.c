//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to calculate the checksum of a string
unsigned int calculate_checksum(char* str) {
    unsigned int sum = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        sum += str[i];
    }
    return sum;
}

// Function to generate a random string of a given length
char* generate_random_string(int length) {
    char* str = (char*)malloc(length + 1);
    int i;
    for (i = 0; i < length; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[length] = '\0';
    return str;
}

int main() {
    char* input_string;
    char* random_string;
    unsigned int checksum;

    printf("Welcome to the Funny C Checksum Calculator!\n");
    printf("Please enter a string: ");
    scanf("%s", input_string);

    // Calculate the checksum of the input string
    checksum = calculate_checksum(input_string);

    // Generate a random string of the same length as the input string
    random_string = generate_random_string(strlen(input_string));

    // Print the results in a funny way
    printf("\nYour input string: %s\n", input_string);
    printf("Checksum of the input string: %u\n", checksum);
    printf("Random string of the same length: %s\n", random_string);
    printf("Checksum of the random string: %u\n", calculate_checksum(random_string));

    free(random_string);
    return 0;
}