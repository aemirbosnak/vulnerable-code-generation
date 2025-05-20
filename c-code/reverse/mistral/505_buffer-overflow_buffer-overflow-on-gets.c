#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_CODE_LENGTH 10
#define MAX_ALIEN_TYPE 10
#define MAX_ALIEN_STRENGTH 100

int main() {
    char name[MAX_NAME_LENGTH];
    char code[MAX_CODE_LENGTH];
    int alien_type, alien_strength;
    int secret_code[] = {12345, 67890};
    int random_number;
    double probability;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter your authorization code: ");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = '\0';

    if (strcmp(code, secret_code[0]) == 0 || strcmp(code, secret_code[1]) == 0) {
        printf("Access granted.\n");
        printf("Enter alien type (1-10): ");
        scanf("%d", &alien_type);
        printf("Enter alien strength (1-100): ");
        scanf("%d", &alien_strength);

        srand(time(NULL));
        random_number = rand() % 100 + 1;

        probability = (alien_type * alien_strength) / random_number;
        printf("Probability of alien invasion: %.2f%%\n", probability * 100);
    } else {
        printf("Invalid authorization code.\n");
    }

    return 0;
}
