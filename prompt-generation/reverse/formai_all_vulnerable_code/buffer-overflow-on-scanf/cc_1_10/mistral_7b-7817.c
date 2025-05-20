//MISTRAL-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERMS 10

typedef struct {
    char name[50];
    int fib;
} Person;

void print_name(Person person) {
    printf("%s: %d\n", person.name, person.fib);
}

Person fibonacci_person(int n) {
    Person p[MAX_TERMS];
    int i;

    strcpy(p[0].name, "I");
    p[0].fib = 0;

    strcpy(p[1].name, "You");
    p[1].fib = 1;

    for (i = 2; i < n; i++) {
        Person temp;

        strcpy(temp.name, malloc(strlen(p[i - 1].name) + strlen(p[i - 2].name) + 2));
        strcat(strcat(strcpy(temp.name, p[i - 1].name), " and "), p[i - 2].name);

        temp.fib = p[i - 1].fib + p[i - 2].fib;

        if (i < MAX_TERMS - 1) {
            p[i] = temp;
        } else {
            print_name(temp);
        }
    }

    return p[n - 1];
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n > MAX_TERMS) {
        printf("Error: Number of terms too large.\n");
        return 1;
    }

    Person fib_person = fibonacci_person(n);

    printf("\nThe %dth Fibonacci number is: %d\n", n, fib_person.fib);

    return 0;
}