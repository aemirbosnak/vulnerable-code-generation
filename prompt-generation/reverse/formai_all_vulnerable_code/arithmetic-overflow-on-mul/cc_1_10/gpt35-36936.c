//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to generate random numbers
int generate_random_number(int max_value) {
    return rand() % max_value + 1;
}

// function to calculate GCD of two numbers
int gcd(int a, int b) {
    int temp;
    while(b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// function to calculate exponentiation modulo
int power_modulo(int a, int b, int n) {
    int result = 1;
    while(b > 0) {
        if(b % 2 == 1) {
            result = (result * a) % n;
        }
        a = (a * a) % n;
        b /= 2;
    }
    return result;
}

int main() {
    srand(time(NULL));
    int p = 13, q = 17;
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    int e, d, k;

    // generating e value
    while(1) {
        e = generate_random_number(phi_n - 1);
        if(gcd(e, phi_n) == 1) {
            break;
        }
    }

    // calculating d value
    k = 1;
    while(1) {
        d = (k * phi_n + 1) / e;
        if(d * e == k * phi_n + 1) {
            break;
        }
        k++;
    }

    // user input
    int input_num;
    printf("Enter a number to encrypt: ");
    scanf("%d", &input_num);

    // encryption
    int encrypted_num = power_modulo(input_num, e, n);
    printf("Encrypted result: %d\n", encrypted_num);

    // decryption
    int decrypted_num = power_modulo(encrypted_num, d, n);
    printf("Decrypted result: %d\n", decrypted_num);
    
    return 0;
}