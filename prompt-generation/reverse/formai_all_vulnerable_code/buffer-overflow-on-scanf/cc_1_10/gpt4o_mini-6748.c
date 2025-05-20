//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t due_time;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void print_welcome() {
    printf("🎉 Welcome to the Cheerful Task Scheduler! 🎉\n");
    printf("Let's organize your tasks and bring some sunshine to your day! ☀️\n");
}

void print_tasks() {
    if (task_count == 0) {
        printf("🌼 You have no tasks scheduled! 🌼\n");
        return;
    }
    printf("\n📋 Your Scheduled Tasks: 📋\n");
    for (int i = 0; i < task_count; i++) {
        char due_time[20];
        strftime(due_time, sizeof(due_time), "%Y-%m-%d %H:%M:%S", localtime(&task_list[i].due_time));
        printf("%d. %s - Due by: %s\n", i + 1, task_list[i].name, due_time);
    }
    printf("\n");
}

void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("😞 Oops! You can't add more tasks. Maximum limit reached! 😞\n");
        return;
    }

    Task new_task;
    printf("📝 Enter the name of your new task: ");
    fgets(new_task.name, TASK_NAME_LENGTH, stdin);
    new_task.name[strcspn(new_task.name, "\n")] = '\0'; // Remove newline character

    printf("🌟 When is this task due? (Enter date in YYYY-MM-DD format): ");
    char date_str[11];
    fgets(date_str, sizeof(date_str), stdin);
    date_str[strcspn(date_str, "\n")] = '\0'; // Remove newline character

    struct tm tm = {0};
    sscanf(date_str, "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);
    tm.tm_year -= 1900; // Years since 1900
    tm.tm_mon -= 1; // Months since January
    new_task.due_time = mktime(&tm);

    task_list[task_count++] = new_task;
    printf("🎈 Yay! Task \"%s\" has been added and is due on %s! 🎈\n", new_task.name, date_str);
}

void delete_task() {
    if (task_count == 0) {
        printf("😞 No tasks to delete! Please add some tasks first. 😞\n");
        return;
    }
    print_tasks();

    int task_number;
    printf("❗ Enter the task number you want to delete: ");
    scanf("%d", &task_number);
    getchar(); // Consume newline character

    if (task_number < 1 || task_number > task_count) {
        printf("😟 Invalid task number! Please try again. 😟\n");
        return;
    }

    printf("👋 Bye bye, task \"%s\"! You've been deleted! 👋\n", task_list[task_number - 1].name);
    for (int i = task_number - 1; i < task_count - 1; i++) {
        task_list[i] = task_list[i + 1];
    }
    task_count--;
}

void menu() {
    int choice;
    do {
        printf("\n🌈 Main Menu 🌈\n");
        printf("1. Add a Task\n");
        printf("2. Delete a Task\n");
        printf("3. View Tasks\n");
        printf("4. Exit\n");
        printf("🎯 Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                delete_task();
                break;
            case 3:
                print_tasks();
                break;
            case 4:
                printf("💫 Thank you for using the Cheerful Task Scheduler! Stay happy! 💫\n");
                break;
            default:
                printf("🚫 Invalid choice! Please select between 1-4. 🚫\n");
        }
    } while (choice != 4);
}

int main() {
    print_welcome();
    menu();
    return 0;
}