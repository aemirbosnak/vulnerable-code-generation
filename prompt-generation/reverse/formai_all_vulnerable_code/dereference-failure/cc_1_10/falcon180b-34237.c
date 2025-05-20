//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// define a function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// define a function to generate a random boolean value
int rand_bool() {
    return rand() % 2;
}

// define a function to generate a random string of given length
char* rand_str(int length) {
    char* str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[length] = '\0';
    return str;
}

// define a function to generate a random integer
int rand_int() {
    return rand();
}

// define a function to generate a random float
float rand_float() {
    return (float)rand() / RAND_MAX;
}

// define a function to generate a random double
double rand_double() {
    return (double)rand() / RAND_MAX;
}

int main() {
    // seed the random number generator with the current time
    srand(time(NULL));

    // generate a random number between 1 and 100
    int num = rand_num(1, 100);
    printf("Random number between 1 and 100: %d\n", num);

    // generate a random boolean value
    int bool_value = rand_bool();
    printf("Random boolean value: %d\n", bool_value);

    // generate a random string of length 10
    char* str = rand_str(10);
    printf("Random string of length 10: %s\n", str);
    free(str);

    // generate a random integer
    int int_value = rand_int();
    printf("Random integer: %d\n", int_value);

    // generate a random float
    float float_value = rand_float();
    printf("Random float: %f\n", float_value);

    // generate a random double
    double double_value = rand_double();
    printf("Random double: %f\n", double_value);

    return 0;
}