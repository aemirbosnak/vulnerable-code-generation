//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BRAVE_MAX_INT 1000000000
#define BRAVE_MIN_INT -1000000000

int brave_add(int a, int b) {
    if (a > BRAVE_MAX_INT / 2) {
        return BRAVE_MAX_INT;
    } else if (b > BRAVE_MAX_INT / 2) {
        return BRAVE_MAX_INT;
    } else {
        return a + b;
    }
}

int brave_sub(int a, int b) {
    if (a > BRAVE_MAX_INT / 2) {
        return BRAVE_MAX_INT;
    } else if (b > BRAVE_MAX_INT / 2) {
        return BRAVE_MAX_INT;
    } else {
        return a - b;
    }
}

int brave_mul(int a, int b) {
    if (a > BRAVE_MAX_INT / 2) {
        return BRAVE_MAX_INT;
    } else if (b > BRAVE_MAX_INT / 2) {
        return BRAVE_MAX_INT;
    } else {
        return a * b;
    }
}

int brave_div(int a, int b) {
    if (a > BRAVE_MAX_INT / 2) {
        return BRAVE_MAX_INT;
    } else if (b > BRAVE_MAX_INT / 2) {
        return BRAVE_MAX_INT;
    } else if (b == 0) {
        return BRAVE_MIN_INT;
    } else {
        return a / b;
    }
}

int main() {
    int a, b, c;
    char brave_message[100];

    printf("Welcome to Brave Arithmetic! \n");

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    c = brave_add(a, b);
    if (c == BRAVE_MAX_INT) {
        sprintf(brave_message, "Oops! The result exceeds the maximum limit of %ld!", BRAVE_MAX_INT);
    } else {
        sprintf(brave_message, "The result is %d", c);
    }

    printf("%s\n", brave_message);

    c = brave_sub(a, b);
    if (c == BRAVE_MAX_INT) {
        sprintf(brave_message, "Oops! The result exceeds the maximum limit of %ld!", BRAVE_MAX_INT);
    } else {
        sprintf(brave_message, "The result is %d", c);
    }

    printf("%s\n", brave_message);

    c = brave_mul(a, b);
    if (c == BRAVE_MAX_INT) {
        sprintf(brave_message, "Oops! The result exceeds the maximum limit of %ld!", BRAVE_MAX_INT);
    } else {
        sprintf(brave_message, "The result is %d", c);
    }

    printf("%s\n", brave_message);

    c = brave_div(a, b);
    if (c == BRAVE_MAX_INT) {
        sprintf(brave_message, "Oops! The result exceeds the maximum limit of %ld!", BRAVE_MAX_INT);
    } else if (c == BRAVE_MIN_INT) {
        sprintf(brave_message, "Oops! The result is negative!");
    } else {
        sprintf(brave_message, "The result is %d", c);
    }

    printf("%s\n", brave_message);

    return 0;
}