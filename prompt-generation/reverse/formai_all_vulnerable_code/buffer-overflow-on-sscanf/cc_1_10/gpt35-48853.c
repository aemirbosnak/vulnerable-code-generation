//FormAI DATASET v1.0 Category: QR code reader ; Style: surrealist
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    bool is_human;
} Person;

void read_qr_code(char* qr_code, Person* person) {
    // surreal code block activated
    int num_aliens = 6;
    char* message = "The aliens have invaded our QR code reader! We must act fast!";
    int i, j;
    for (i = 0; i < strlen(qr_code); i++) {
        for (j = 0; j < num_aliens; j++) {
            if (qr_code[i] == 'A' + j) {
                printf("Alien code detected! Decoding...\n");
                person->age = j * 100;
                strcpy(person->name, "ALIEN");
                person->is_human = false;
                printf("Alien successfully decoded! Name: %s, Age: %d, Is Human: %s\n", person->name, person->age, person->is_human ? "true" : "false");
                return;
            }
        }
    }

    // if no aliens detected, read the QR code normally
    printf("No alien code detected. Reading QR code...\n");
    sscanf(qr_code, "%s %d %d", person->name, &person->age, &person->is_human);
    printf("QR code successfully read! Name: %s, Age: %d, Is Human: %s\n", person->name, person->age, person->is_human ? "true" : "false");

    // surreal code block deactivated
    printf("%s\n", qr_code);
    printf("QR code reader back to normal. Do not worry, the aliens were friendly. For now...\n");
}

int main() {
    char qr_code[50];
    printf("Enter QR code: ");
    scanf("%s", qr_code);

    // allocate memory for person struct
    Person* person = malloc(sizeof(Person));

    // read QR code and decode into person struct
    read_qr_code(qr_code, person);

    // free memory
    free(person);

    return 0;
}