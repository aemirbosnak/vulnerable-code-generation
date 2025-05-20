//Falcon-180B DATASET v1.0 Category: Recursive ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate a random number between min and max
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random string of given length
char* randStr(int len) {
    char* str = (char*)malloc(len + 1); // Allocate memory for the string and the null terminator
    str[len] = '\0'; // Set the null terminator
    for(int i=0; i<len; i++) {
        str[i] = rand() % 26 + 'a'; // Generate a random lowercase letter
    }
    return str;
}

// Function to generate a random object
struct randomObj {
    int num;
    char* str;
};

struct randomObj randObj() {
    struct randomObj obj;
    obj.num = randInt(1, 100);
    obj.str = randStr(10);
    return obj;
}

// Recursive function to print an array of random objects
void printArr(struct randomObj* arr, int n) {
    if(n == 0) {
        return;
    }
    printf("Element %d: ", n);
    printf("Number: %d, String: %s\n", arr[n].num, arr[n].str);
    printArr(arr, n-1);
}

// Main function to generate an array of random objects and print it
int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int n = randInt(1, 10); // Generate a random array size between 1 and 10
    struct randomObj* arr = (struct randomObj*)malloc(n * sizeof(struct randomObj)); // Allocate memory for the array
    for(int i=0; i<n; i++) {
        arr[i] = randObj(); // Generate a random object and assign it to the array
    }
    printf("Random array of objects:\n");
    printArr(arr, n);
    return 0;
}