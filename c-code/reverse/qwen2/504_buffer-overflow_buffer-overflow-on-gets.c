#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char name[20];
    int age;
    float height;

    printf("Enter your name: ");
    gets(name); // Vulnerable to buffer overflow

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your height in meters: ");
    scanf("%f", &height);

    if (age > 18) {
        if (height >= 1.75) {
            if (strcmp(name, "Zorg") == 0) {
                printf("High probability of invasion\n");
            } else {
                printf("Medium probability of invasion\n");
            }
        } else {
            printf("Low probability of invasion\n");
        }
    } else {
        printf("No probability of invasion\n");
    }

    return 0;
}
