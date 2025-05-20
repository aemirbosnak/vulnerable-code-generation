//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

struct Fitness
{
    char name[50];
    int age;
    float weight;
    float height;
    int calories_consumed;
    int calories_burned;
    int steps_taken;
};

void display_menu()
{
    printf("1. Enter Profile Details\n");
    printf("2. Enter Calories Consumed\n");
    printf("3. Enter Calories Burned\n");
    printf("4. Enter Steps Taken\n");
    printf("5. View Today's Progress\n");
    printf("6. Quit\n");
}

void enter_profile_details(struct Fitness *f)
{
    printf("Enter your Name: ");
    scanf("%s", f->name);

    printf("Enter your Age: ");
    scanf("%d", &f->age);

    printf("Enter your Weight (in kgs): ");
    scanf("%f", &f->weight);

    printf("Enter your Height (in meters): ");
    scanf("%f", &f->height);

    printf("Profile Details Entered Successfully!\n\n");
}

void enter_calories_consumed(struct Fitness *f)
{
    int calories;

    printf("Enter Calories Consumed Today: ");
    scanf("%d", &calories);

    f->calories_consumed += calories;

    printf("Calories Consumed Entered Successfully!\n\n");
}

void enter_calories_burned(struct Fitness *f)
{
    int calories;

    printf("Enter Calories Burned Today: ");
    scanf("%d", &calories);

    f->calories_burned += calories;

    printf("Calories Burned Entered Successfully!\n\n");
}

void enter_steps_taken(struct Fitness *f)
{
    int steps;

    printf("Enter Steps Taken Today: ");
    scanf("%d", &steps);

    f->steps_taken += steps;

    printf("Steps Taken Entered Successfully!\n\n");
}

void view_progress(struct Fitness *f)
{
    float bmi = (f->weight) / ((f->height)*(f->height));
    int calories_net = f->calories_consumed - f->calories_burned;

    printf("Name: %s\n", f->name);
    printf("Age: %d years\n", f->age);
    printf("Weight: %.2f kgs\n", f->weight);
    printf("Height: %.2f meters\n", f->height);
    printf("BMI: %.2f\n", bmi);
    printf("Calories Consumed: %d kcal\n", f->calories_consumed);
    printf("Calories Burned: %d kcal\n", f->calories_burned);
    printf("Calories Net: %d kcal\n", calories_net);
    printf("Steps Taken: %d\n\n", f->steps_taken);
}

int main()
{
    struct Fitness f;
    int choice;

    while(1)
    {
        display_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enter_profile_details(&f);
                break;
            case 2:
                enter_calories_consumed(&f);
                break;
            case 3:
                enter_calories_burned(&f);
                break;
            case 4:
                enter_steps_taken(&f);
                break;
            case 5:
                view_progress(&f);
                break;
            case 6:
                printf("Exiting Fitness Tracker...\n");
                exit(0);
            default:
                printf("Invalid Input. Please Try Again!\n\n");
        }
    }

    return 0;
}