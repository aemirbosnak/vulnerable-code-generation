//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>

// Struct for holding intrusion information
typedef struct {
    char ip[16];
    int failed_attempts;
    bool blocked;
} Intrusion;

int main() {
    Intrusion intrusions[10]; // In real world this should be a dynamic array or linked list
    int num_intrusions = 0;

    while (true) {
        char ip[16];
        printf("Enter IP address: ");
        scanf("%s", ip);

        bool already_exists = false;
        for (int i = 0; i < num_intrusions; i++) {
            if (strcmp(intrusions[i].ip, ip) == 0) {
                already_exists = true;
                intrusions[i].failed_attempts++;
                if (intrusions[i].failed_attempts >= 3) {
                    intrusions[i].blocked = true;
                }
                break;
            }
        }

        if (!already_exists) {
            Intrusion new_intrusion = { .failed_attempts = 1 };
            strcpy(new_intrusion.ip, ip);
            if (new_intrusion.failed_attempts >= 3) {
                new_intrusion.blocked = true;
            }
            intrusions[num_intrusions] = new_intrusion;
            num_intrusions++;
        }

        printf("Intrusion log:\n");
        for (int i = 0; i < num_intrusions; i++) {
            printf("%s - Failed attempts: %d - Blocked: %s\n", 
                intrusions[i].ip,
                intrusions[i].failed_attempts,
                intrusions[i].blocked ? "Yes" : "No"
            );
        }
    }

    return 0;
}