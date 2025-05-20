//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIGNALS 10
#define MAX_SSID_LEN 20

typedef struct {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} WiFiSignal;

void clear_input() {
    while(getchar() != '\n');
}

int get_user_choice() {
    int choice;
    printf("\n\n");
    printf("Wi-Fi Signal Analyzer\n");
    printf("--------------------\n");
    printf("[1] Add signal\n");
    printf("[2] View signals\n");
    printf("[3] Analyze signals\n");
    printf("[4] Exit\n\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);
    clear_input();
    return choice;
}

void add_signal(WiFiSignal signals[], int *num_signals) {
    if(*num_signals == MAX_SIGNALS) {
        printf("Maximum number of signals reached.\n");
        return;
    }
    printf("Enter SSID (max %d characters): ", MAX_SSID_LEN);
    fgets(signals[*num_signals].ssid, MAX_SSID_LEN, stdin);
    signals[*num_signals].ssid[strcspn(signals[*num_signals].ssid, "\n")] = '\0';
    printf("Enter signal strength (0-100): ");
    scanf("%d", &(signals[*num_signals].signal_strength));
    clear_input();
    (*num_signals)++;
}

void view_signals(WiFiSignal signals[], int num_signals) {
    if(num_signals == 0) {
        printf("No signals found.\n");
        return;
    }
    printf("SSID\t\tSignal Strength\n");
    printf("---------------------------------\n");
    for(int i = 0; i < num_signals; i++) {
        printf("%-20s%d\n", signals[i].ssid, signals[i].signal_strength);
    }
}

void analyze_signals(WiFiSignal signals[], int num_signals) {
    if(num_signals == 0) {
        printf("No signals found.\n");
        return;
    }
    int strong_signals = 0;
    int weak_signals = 0;
    int total_strength = 0;
    for(int i = 0; i < num_signals; i++) {
        total_strength += signals[i].signal_strength;
        if(signals[i].signal_strength > 50) {
            strong_signals++;
        } else {
            weak_signals++;
        }
    }
    float average_strength = (float) total_strength / num_signals;
    printf("Analysis Results\n");
    printf("----------------\n");
    printf("Number of strong signals: %d\n", strong_signals);
    printf("Number of weak signals: %d\n", weak_signals);
    printf("Average signal strength: %.2f\n", average_strength);
}

int main() {
    WiFiSignal signals[MAX_SIGNALS];
    int num_signals = 0;
    int choice;
    do {
        choice = get_user_choice();
        switch(choice) {
            case 1:
                add_signal(signals, &num_signals);
                break;
            case 2:
                view_signals(signals, num_signals);
                break;
            case 3:
                analyze_signals(signals, num_signals);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 4);
    return 0;
}