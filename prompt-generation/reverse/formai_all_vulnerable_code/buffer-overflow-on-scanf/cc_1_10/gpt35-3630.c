//FormAI DATASET v1.0 Category: Temperature monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TEMP 100
#define MIN_TEMP 0
#define MAX_ALERTS 5

int alerts[MAX_ALERTS];
int num_alerts = 0;

bool in_alerts(int temp) {
    for (int i = 0; i < num_alerts; ++i) {
        if (alerts[i] == temp) {
            return true;
        }
    }
    return false;
}

void add_alert(int temp) {
    if (num_alerts >= MAX_ALERTS) {
        return;
    }
    alerts[num_alerts++] = temp;
}

int main() {
    int temp;
    printf("Enter current temperature: ");
    scanf("%d", &temp);

    while (temp != -1) {
        if (temp > MAX_TEMP) {
            printf("Temperature is higher than maximum limit.\n");
            if (!in_alerts(temp)) {
                add_alert(temp);
                printf("Alert: Temperature Exceeds %d\n", temp);
            }
        }
        else if (temp < MIN_TEMP) {
            printf("Temperature is lower than minimum limit.\n");
            if (!in_alerts(temp)) {
                add_alert(temp);
                printf("Alert: Temperature Below %d\n", temp);
            }
        }
        else {
            printf("Temperature is within limits.\n");
        }

        printf("Enter current temperature (-1 to exit): ");
        scanf("%d", &temp);
    }

    printf("\nAlerts:\n");
    for (int i = 0; i < num_alerts; ++i) {
        printf("%d\n", alerts[i]);
    }

    return EXIT_SUCCESS;
}