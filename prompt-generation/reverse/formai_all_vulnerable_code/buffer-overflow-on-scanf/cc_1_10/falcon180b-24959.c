//Falcon-180B DATASET v1.0 Category: Recursive ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random string of length n
char* rand_string(int n) {
    char* str = (char*)malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[n] = '\0';
    return str;
}

// Function to print a string in reverse order
void reverse_string(char* str) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}

// Recursive function to print a string n times
void print_n_times(char* str, int n) {
    if (n == 0) {
        return;
    }
    printf("%s", str);
    print_n_times(str, n - 1);
}

// Recursive function to generate a random password of length n
void generate_password(int n) {
    char* password = rand_string(n);
    printf("Random password: ");
    reverse_string(password);
    printf("%s\n", password);
    free(password);
}

// Recursive function to generate multiple passwords of length n
void generate_multiple_passwords(int n, int m) {
    if (m == 0) {
        return;
    }
    generate_password(n);
    generate_multiple_passwords(n, m - 1);
}

int main() {
    srand(time(NULL));
    int n, m;
    printf("Enter the length of the password: ");
    scanf("%d", &n);
    printf("Enter the number of passwords to generate: ");
    scanf("%d", &m);
    generate_multiple_passwords(n, m);
    return 0;
}