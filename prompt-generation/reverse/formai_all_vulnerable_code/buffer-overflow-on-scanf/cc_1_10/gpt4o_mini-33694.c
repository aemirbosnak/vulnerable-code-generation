//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TEMP 100
#define MIN_TEMP -30
#define ALERT_TEMP 80

void display_welcome_message() {
    printf("***********************************\n");
    printf("**  Welcome to the Temperature   **\n");
    printf("**         Monitor System        **\n");
    printf("***********************************\n");
    printf("Startup in progress...\n");
    sleep(1);
    printf("Getting ready to watch over temperatures!\n");
    sleep(1);
}

int get_random_temperature() {
    return (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
}

void check_temperature(int temperature) {
    if (temperature >= ALERT_TEMP) {
        printf("⚠️  ALERT: Current temperature is %d°C! Time to cool down! ⚠️\n", temperature);
    } else {
        printf("✅ Current temperature is %d°C. All systems normal. ✅\n", temperature);
    }
}

void log_temperature(int temperature) {
    FILE *file = fopen("temperature_log.txt", "a");
    if (file == NULL) {
        printf("❌ Error opening log file! ❌\n");
        return;
    }
    
    time_t now;
    time(&now);
    fprintf(file, "Temperature: %d°C at %s", temperature, ctime(&now));
    fclose(file);
}

void display_exit_message() {
    printf("***********************************\n");
    printf("**  Thank You for using the      **\n");
    printf("**  Temperature Monitor System!   **\n");
    printf("***********************************\n");
}

int main() {
    srand(time(0));  // Initialize random number generator
    display_welcome_message();

    char choice;
    do {
        int current_temp = get_random_temperature();
        check_temperature(current_temp);
        log_temperature(current_temp);

        printf("Do you want to continue monitoring? (y/n): ");
        scanf(" %c", &choice);
        printf("\n");

    } while (choice == 'y' || choice == 'Y');

    display_exit_message();
    return 0;
}