//Gemma-7B DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Virus {
    char name[50];
    char description[200];
    int damage;
    int detection_method;
} Virus;

Virus viruses[] = {
    {"Trojan Horse", "A classic Trojan horse that can be used to spy on your computer.", 10, 1},
    {"Worms", "A group of self-replicating malware that can cause damage to your computer.", 8, 2},
    {"Ransomware", "Malware that encrypts your files and demands a ransom payment.", 9, 3},
    {"Spyware", "Software that secretly collects information about your computer activity.", 7, 4}
};

int main() {
    char filename[100];
    printf("Enter the name of the file you want to scan:");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file) {
        for (int i = 0; i < 4; i++) {
            Virus virus = viruses[i];
            char *virus_name = virus.name;
            char *virus_description = virus.description;
            int virus_damage = virus.damage;
            int virus_detection_method = virus.detection_method;

            if (strstr(filename, virus_name) != NULL) {
                printf("WARNING: Virus detected: %s\n", virus_name);
                printf("Description: %s\n", virus_description);
                printf("Damage: %d\n", virus_damage);
                printf("Detection method: %d\n", virus_detection_method);

                fclose(file);
                return 1;
            }
        }

        fclose(file);
        printf("No viruses found.\n");
    } else {
        printf("Error opening file.\n");
    }

    return 0;
}