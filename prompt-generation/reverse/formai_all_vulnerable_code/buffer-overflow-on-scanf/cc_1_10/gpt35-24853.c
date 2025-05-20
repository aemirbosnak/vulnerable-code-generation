//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_IP_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    int count;
} attack_t;

void print_menu();
void add_attack(char* ip, attack_t* attacks, int* num_attacks);
void print_attacks(attack_t* attacks, int num_attacks);

int main() {
    attack_t attacks[100];
    int num_attacks = 0;

    printf("Welcome to the Peaceful Intrusion Detection System.\n");

    while (1) {
        print_menu();

        int option;
        printf("Enter your choice: ");
        scanf("%d", &option);

        if (option == 1) {
            char line[MAX_LINE_LENGTH];

            printf("Enter the log line: ");
            getchar();
            fgets(line, MAX_LINE_LENGTH, stdin);

            char* ip = strtok(line, " ");
            add_attack(ip, attacks, &num_attacks);
        } else if (option == 2) {
            print_attacks(attacks, num_attacks);
        } else if (option == 3) {
            printf("Exiting the Peaceful Intrusion Detection System.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("\n1. Add log entry\n");
    printf("2. Show attacks\n");
    printf("3. Exit\n");
}

void add_attack(char* ip, attack_t* attacks, int* num_attacks) {
    int i;
    for (i = 0; i < *num_attacks; i++) {
        if (strcmp(attacks[i].ip, ip) == 0) {
            attacks[i].count++;
            return;
        }
    }

    strncpy(attacks[*num_attacks].ip, ip, MAX_IP_LENGTH);
    attacks[*num_attacks].count = 1;

    (*num_attacks)++;
}

void print_attacks(attack_t* attacks, int num_attacks) {
    printf("\nIP\t\tNumber of attacks\n");
    printf("-------------------------------------------\n");

    int i;
    for (i = 0; i < num_attacks; i++) {
        printf("%s\t\t%d\n", attacks[i].ip, attacks[i].count);
    }
}