//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

typedef struct {
    int a, b, c, d;
} CustomInt;

typedef struct {
    char name[50];
    int age;
    CustomInt num;
} Person;

Person createPerson(const char* name, int age, int a, int b, int c, int d) {
    Person newPerson;
    strcpy(newPerson.name, name);
    newPerson.age = age;
    newPerson.num.a = a;
    newPerson.num.b = b;
    newPerson.num.c = c;
    newPerson.num.d = d;
    return newPerson;
}

int main() {
    int x = 0, y = 0, z = 0;
    Person p1, p2;

    printf("Enter three integers: ");
    scanf("%d%d%d", &x, &y, &z);

    p1 = createPerson("Alice", 25, x, y, pow(2, 3) + 1, 2 * y - x);
    p2 = createPerson("Bob", 30, x + y, y * 2, sqrt(pow(x, 2) + pow(y, 2)), y % x);

    printf("\nPerson 1:\n");
    printf("Name: %s\n", p1.name);
    printf("Age: %d\n", p1.age);
    printf("Numbers: a=%d, b=%d, c=%d, d=%d\n", p1.num.a, p1.num.b, p1.num.c, p1.num.d);

    printf("\nPerson 2:\n");
    printf("Name: %s\n", p2.name);
    printf("Age: %d\n", p2.age);
    printf("Numbers: a=%d, b=%d, c=%d, d=%d\n", p2.num.a, p2.num.b, p2.num.c, p2.num.d);

    if (p1.age > p2.age) {
        printf("\nPerson 1 is older than Person 2.\n");
    } else {
        printf("\nPerson 2 is older than or the same age as Person 1.\n");
    }

    int sum = p1.num.a + p1.num.b + p1.num.c + p1.num.d + p2.num.a + p2.num.b + p2.num.c + p2.num.d;
    printf("\nThe sum of the numbers of both persons is: %d\n", sum);

    int fileDescriptor = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fileDescriptor == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (write(fileDescriptor, "This is the content of the file.\n", strlen("This is the content of the file.\n")) == -1) {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }

    if (close(fileDescriptor) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    printf("\nThe content of the file has been written successfully.\n");

    return 0;
}