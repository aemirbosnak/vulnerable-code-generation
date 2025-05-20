//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STR_MAX_LENGTH 256
#define MAX_ATTACKS 100

// Structure to store information about an attack
typedef struct Attack {
    char sourceIP[STR_MAX_LENGTH];
    char destinationIP[STR_MAX_LENGTH];
    char type[STR_MAX_LENGTH];
    char timestamp[STR_MAX_LENGTH];
} Attack;

// Function to check if two IPs are the same
int isSameIP(char* ip1, char* ip2) {
    return strcmp(ip1, ip2) == 0;
}

// Function to check if two attacks are the same
int isSameAttack(Attack* attack1, Attack* attack2) {
    return isSameIP(attack1->sourceIP, attack2->sourceIP) &&
            isSameIP(attack1->destinationIP, attack2->destinationIP) &&
            strcmp(attack1->type, attack2->type) == 0;
}

// Function to add an attack to an array of attacks
void addAttack(Attack* attack, Attack* attacks, int* numAttacks) {
    int i;
    // Check if this attack is already in the array
    for(i=0; i<*numAttacks; i++) {
        if(isSameAttack(attack, &attacks[i])) {
            return;
        }
    }
    // Add the attack to the array
    attacks[*numAttacks] = *attack;
    (*numAttacks)++;
}

// Function to parse a line of input and extract an attack
void parseLine(char* line, Attack* attack) {
    sscanf(line, "%[^,],%[^,],%[^,],%s", attack->sourceIP, attack->destinationIP, attack->type, attack->timestamp);
}

int main() {
    char filename[STR_MAX_LENGTH];
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("Could not open file\n");
        return 0;
    }
    Attack attacks[MAX_ATTACKS];
    int numAttacks = 0;
    char line[STR_MAX_LENGTH];
    while(fgets(line, STR_MAX_LENGTH, file) != NULL) {
        Attack attack;
        parseLine(line, &attack);
        addAttack(&attack, attacks, &numAttacks);
    }
    fclose(file);
    printf("Unique attacks detected: %d\n", numAttacks);
    return 0;
}