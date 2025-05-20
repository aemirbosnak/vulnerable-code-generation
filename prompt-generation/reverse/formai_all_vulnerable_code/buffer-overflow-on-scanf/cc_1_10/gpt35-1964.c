//FormAI DATASET v1.0 Category: Data recovery tool ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

int main() {

    printf("Welcome to the mystical world of data recovery!\n");
    printf("You have lost your data, but don't worry, it's hidden inside a magical box.\n");
    printf("Do you dare to open the box and recover your data? (y/n)\n");

    char choice;
    scanf("%c", &choice);

    if (choice == 'y') {

        for (int i = 10; i > 0; i--) {
        
            printf("The box is locked! Crack the code in %d attempts.\n", i);

            int code = rand() % 1000;

            int guess, tries = 0;
            do {
                printf("Enter the 3-digit code: ");
                scanf("%d", &guess);
                tries++;

                if (guess < code)
                    printf("The code is greater than your guess.\n");
                else if (guess > code)
                    printf("The code is less than your guess.\n");
                else {
                    printf("Congratulations! You have cracked the code!\n");

                    FILE* file_ptr = fopen("recovered_data.txt", "r");
                    if (file_ptr == NULL) {
                        printf("Ooops, it seems I couldn't recover your data.\n");
                        printf("I have a backup plan though, just give me some time...\n");
                        FILE* backup_file_ptr = fopen("backup_data.txt", "w");
                        fprintf(backup_file_ptr, "Your data is gone, forever lost in the digital void.\n");
                        fclose(backup_file_ptr);
                        printf("Phew, that was close! I made a backup plan for you. Check backup_data.txt.\n");
                    }
                    else {
                        printf("Your data is safe and sound! Check recovered_data.txt.\n");
                        fclose(file_ptr);
                    }

                    return 0;
                }
            } while (tries < 3);

            printf("Sorry, you failed to crack the code.\n");
        }

        printf("The box exploded, destroying your data forever. Thanks for playing!\n");
    }
    else
        printf("Oh, I see. You don't trust me enough to recover your data. Farewell!\n");

    return 0;
}