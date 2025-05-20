//FormAI DATASET v1.0 Category: Computer Biology ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the Human Body Operating System (HBOS) version 1.0!\n");

    int brain_memory = 100; // brain memory in GB
    float stomach_capacity = 3.5; // stomach capacity in liters
    char taste_preference = 'S'; // S for spicy, S for sweet, B for both
    int heart_rate = 75; // resting heart rate in beats per minute
    float blood_glucose_level = 100; // blood glucose level in mg/dL
    char gender = 'M'; // M for male, F for female, O for other

    printf("Your HBOS configuration is:\n");
    printf("-Brain memory: %d GB\n", brain_memory);
    printf("-Stomach capacity: %.1f l\n", stomach_capacity);
    printf("-Taste preference: %c\n", taste_preference);
    printf("-Resting heart rate: %d bpm\n", heart_rate);
    printf("-Blood glucose level: %.1f mg/dL\n", blood_glucose_level);
    printf("-Gender: %c\n", gender);

    printf("Would you like to modify any of these parameters? (Y/N) ");

    char answer = getchar();
    if (answer == 'Y' || answer == 'y') {
        printf("Which parameter would you like to modify?\n");
        printf("1) Brain memory\n");
        printf("2) Stomach capacity\n");
        printf("3) Taste preference\n");
        printf("4) Resting heart rate\n");
        printf("5) Blood glucose level\n");
        printf("6) Gender\n");

        int parameter;
        scanf("%d", &parameter);

        switch(parameter) {
            case 1:
                printf("Enter new value for brain memory (in GB): ");
                scanf("%d", &brain_memory);
                printf("Brain memory set to %d GB.\n", brain_memory);
                break;
            case 2:
                printf("Enter new value for stomach capacity (in liters): ");
                scanf("%f", &stomach_capacity);
                printf("Stomach capacity set to %.1f l.\n", stomach_capacity);
                break;
            case 3:
                printf("Enter new value for taste preference (S for spicy, S for sweet, B for both): ");
                getchar(); // clear input buffer
                taste_preference = getchar();
                printf("Taste preference set to %c.\n", taste_preference);
                break;
            case 4:
                printf("Enter new value for resting heart rate (in bpm): ");
                scanf("%d", &heart_rate);
                printf("Resting heart rate set to %d bpm.\n", heart_rate);
                break;
            case 5:
                printf("Enter new value for blood glucose level (in mg/dL): ");
                scanf("%f", &blood_glucose_level);
                printf("Blood glucose level set to %.1f mg/dL.\n", blood_glucose_level);
                break;
            case 6:
                printf("Enter new value for gender (M for male, F for female, O for other): ");
                getchar(); // clear input buffer
                gender = getchar();
                printf("Gender set to %c.\n", gender);
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    
    printf("Thank you for using HBOS version 1.0, have a nice day!\n");

    return 0;
}