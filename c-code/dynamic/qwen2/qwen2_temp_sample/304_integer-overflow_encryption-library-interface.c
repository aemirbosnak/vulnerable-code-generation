#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

// Simulated encryption function with a deliberate integer overflow vulnerability
void encryptData(int data) {
    int key = 123456789;
    // Vulnerable line: Integer overflow due to multiplying large integers
    int result = key * data;

    printf("Encrypted Data: %d\n", result);
}

int main() {
    printf("Security Warning: This program intentionally contains an integer overflow vulnerability.\n");
    printf("Use this only for educational purposes.\n");

    int inputData;
    printf("Enter data to encrypt (must fit within int range): ");
    scanf("%d", &inputData);

    encryptData(inputData);

    return 0;
}
