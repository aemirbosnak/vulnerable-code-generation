//FormAI DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Shape-shifting Digital Diary

int main(){

    int choice, passcode, oldpass, newpass;
    char filename[100], buffer[1000], curdate[20];

    // Initial setup - Creating a new diary or opening existing diary
    printf("\nWelcome to the Shape-shifting Digital Diary!\n");
    printf("Select an option:\n");
    printf("1. Create new diary\n2. Open existing diary\n");
    scanf("%d", &choice);

    // Variables to keep track of current shape
    int shape = 1, maxshape = 4;

    switch(choice){
        case 1:
            printf("\nCreating new diary...\n");
            printf("Enter a filename for your diary: ");
            scanf("%s", filename);

            printf("\nChoose a numeric passcode to protect your diary: ");
            scanf("%d", &passcode);
            break;
        case 2:
            printf("\nEnter filename of diary to open: ");
            scanf("%s", filename);

            printf("\nEnter the passcode to unlock your diary: ");
            scanf("%d", &passcode);
            break;
        default:
            printf("\nInvalid option. Exiting...\n");
            return 0;
    }

    printf("\nDiary opened successfully.\n");

    // Main loop - Shape-shifting interface
    while(1){
        // Shape-shifting interface - Cycle through 4 different shapes
        switch(shape){
            case 1:
                printf("\nShape 1: Basic Text Editor\n");
                printf("Select an option:\n");
                printf("1. Write new entry\n2. View previous entries\n3. Change passcode\n4. Change shape\n5. Exit\n");
                scanf("%d", &choice);

                switch(choice){
                    case 1:
                        printf("\nEnter today's date (MM/DD/YYYY): ");
                        scanf("%s", curdate);

                        FILE *fp;
                        fp = fopen(filename, "a");
                        fprintf(fp, "\n%s\n", curdate);

                        printf("\nEnter your entry (press CRTL+Z to save and exit):\n");
                        while(scanf("%s", buffer) != EOF){
                            fprintf(fp, "%s ", buffer);
                        }
                        fclose(fp);
                        printf("\nEntry saved successfully.\n");
                        break;

                    case 2:
                        printf("\nPrevious entries:\n");

                        FILE *file = fopen(filename, "r");
                        if(file){
                            while(fscanf(file, "%s", buffer) != EOF){
                                printf("%s ", buffer);
                            }
                            fclose(file);
                        }
                        else{
                            printf("No entries found.\n");
                        }

                        break;

                    case 3:
                        printf("\nEnter old passcode: ");
                        scanf("%d", &oldpass);

                        if(oldpass == passcode){
                            printf("\nEnter new passcode: ");
                            scanf("%d", &newpass);

                            passcode = newpass;
                            printf("\nPasscode updated successfully.\n");
                        }
                        else{
                            printf("\nIncorrect passcode. Passcode not changed.\n");
                        }

                        break;

                    case 4:
                        shape = (shape % maxshape) + 1;
                        printf("\nShifting to Shape %d.\n", shape);
                        break;

                    case 5:
                        printf("\nExiting...\n");
                        return 0;

                    default:
                        printf("\nInvalid option.\n");
                }
                break;

            case 2:
                printf("\nShape 2: Calculator\n");
                printf("Select an option:\n");
                printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Change passcode\n6. Change shape\n7. Exit\n");
                scanf("%d", &choice);

                int num1, num2, result;
                switch(choice){
                    case 1:
                        printf("\nEnter two numbers to add: ");
                        scanf("%d %d", &num1, &num2);

                        result = num1 + num2;
                        printf("\n%d + %d = %d\n", num1, num2, result);
                        break;

                    case 2:
                        printf("\nEnter two numbers to subtract: ");
                        scanf("%d %d", &num1, &num2);

                        result = num1 - num2;
                        printf("\n%d - %d = %d\n", num1, num2, result);
                        break;

                    case 3:
                        printf("\nEnter two numbers to multiply: ");
                        scanf("%d %d", &num1, &num2);

                        result = num1 * num2;
                        printf("\n%d * %d = %d\n", num1, num2, result);
                        break;

                    case 4:
                        printf("\nEnter two numbers to divide: ");
                        scanf("%d %d", &num1, &num2);

                        if(num2 == 0){
                            printf("\nMath Error: Division by zero.\n");
                        }
                        else{
                            result = num1 / num2;
                            printf("\n%d / %d = %d\n", num1, num2, result);
                        }
                        break;

                    case 5:
                        printf("\nEnter old passcode: ");
                        scanf("%d", &oldpass);

                        if(oldpass == passcode){
                            printf("\nEnter new passcode: ");
                            scanf("%d", &newpass);

                            passcode = newpass;
                            printf("\nPasscode updated successfully.\n");
                        }
                        else{
                            printf("\nIncorrect passcode. Passcode not changed.\n");
                        }

                        break;

                    case 6:
                        shape = (shape % maxshape) + 1;
                        printf("\nShifting to Shape %d.\n", shape);
                        break;

                    case 7:
                        printf("\nExiting...\n");
                        return 0;

                    default:
                        printf("\nInvalid option.\n");
                }
                break;

            case 3:
                printf("\nShape 3: Tic-Tac-Toe\n");
                printf("Select an option:\n");
                printf("1. Start new game\n2. Change passcode\n3. Change shape\n4. Exit\n");

                scanf("%d", &choice);

                switch(choice){
                    case 1:
                        printf("\nStarting new Tic-Tac-Toe game...\n");
                        printf("TODO: Implement Tic-Tac-Toe game.\n");
                        break;

                    case 2:
                        printf("\nEnter old passcode: ");
                        scanf("%d", &oldpass);

                        if(oldpass == passcode){
                            printf("\nEnter new passcode: ");
                            scanf("%d", &newpass);

                            passcode = newpass;
                            printf("\nPasscode updated successfully.\n");
                        }
                        else{
                            printf("\nIncorrect passcode. Passcode not changed.\n");
                        }

                        break;

                    case 3:
                        shape = (shape % maxshape) + 1;
                        printf("\nShifting to Shape %d.\n", shape);
                        break;

                    case 4:
                        printf("\nExiting...\n");
                        return 0;

                    default:
                        printf("\nInvalid option.\n");
                }
                break;

            case 4:
                printf("\nShape 4: Password Generator\n");
                printf("Select an option:\n");
                printf("1. Generate new password\n2. Change passcode\n3. Change shape\n4. Exit\n");

                scanf("%d", &choice);

                switch(choice){
                    case 1:
                        printf("\nGenerating new password...\n");
                        printf("TODO: Implement password generator.\n");
                        break;

                    case 2:
                        printf("\nEnter old passcode: ");
                        scanf("%d", &oldpass);

                        if(oldpass == passcode){
                            printf("\nEnter new passcode: ");
                            scanf("%d", &newpass);

                            passcode = newpass;
                            printf("\nPasscode updated successfully.\n");
                        }
                        else{
                            printf("\nIncorrect passcode. Passcode not changed.\n");
                        }

                        break;

                    case 3:
                        shape = (shape % maxshape) + 1;
                        printf("\nShifting to Shape %d.\n", shape);
                        break;

                    case 4:
                        printf("\nExiting...\n");
                        return 0;

                    default:
                        printf("\nInvalid option.\n");
                }
                break;
        }
    }

    return 0;
}