//FormAI DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>

// Function to print available tasks to the user
void print_tasks() {
    printf("Available tasks:\n");
    printf("1. Gather wood from the forest\n");
    printf("2. Hunt for deer in the nearby woods\n");
    printf("3. Tend to the fields and harvest crops\n");
    printf("4. Guard the castle walls\n");
    printf("5. Train in sword fighting\n");
}

// Function to perform the task of gathering wood
void gather_wood() {
    printf("You venture out into the forest and start gathering wood.\n");
    printf("After a few hours of hard work, you manage to collect enough wood for the next few days.\n");
    printf("You return to the castle with the wood and store it in the armory.\n");
}

// Function to perform the task of hunting for deer
void hunt_deer() {
    printf("You take your bow and set out into the woods to hunt for deer.\n");
    printf("After a few hours of tracking, you finally manage to spot a majestic buck.\n");
    printf("You aim carefully and let loose an arrow, striking the deer dead center.\n");
    printf("You drag the deer back to the castle and start preparing it for cooking.\n");
}

// Function to perform the task of tending to the fields
void tend_fields() {
    printf("You head out to the fields and start tending to the crops.\n");
    printf("You spend the entire day working hard, pulling weeds and harvesting crops.\n");
    printf("As the sun sets, you head back to the castle with a basket full of fresh produce.\n");
}

// Function to perform the task of guarding the castle walls
void guard_walls() {
    printf("You are assigned to guard the castle walls during the night.\n");
    printf("You spend the entire night patrolling the walls and keeping watch for any signs of danger.\n");
    printf("As the first rays of sunlight start to appear, you are relieved of your duty and head back to your quarters.\n");
}

// Function to perform the task of training in sword fighting
void train_sword() {
    printf("You head to the training grounds to hone your sword fighting skills.\n");
    printf("You spend hours sparring with other knights and honing your techniques.\n");
    printf("As the sun starts to set, you head back to the castle feeling confident in your skills.\n");
}

int main() {
    int task;

    printf("Welcome to the Medieval Task Scheduler!\n");

    while (1) {
        print_tasks();
        printf("Which task would you like to perform? (Enter 0 to quit)\n");
        scanf("%d", &task);

        switch (task) {
            case 0:
                printf("Goodbye!\n");
                return 0;
            case 1:
                gather_wood();
                break;
            case 2:
                hunt_deer();
                break;
            case 3:
                tend_fields();
                break;
            case 4:
                guard_walls();
                break;
            case 5:
                train_sword();
                break;
            default:
                printf("Invalid task number, please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}