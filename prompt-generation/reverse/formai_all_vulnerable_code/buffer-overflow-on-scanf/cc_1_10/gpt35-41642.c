//FormAI DATASET v1.0 Category: Task Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_TASKS_PER_PLAYER 5

typedef struct {
    int task_id;
    int priority;
    int player_id;
    int time_required;
} task_t;

typedef struct {
    int player_id;
    int num_tasks;
    task_t tasks[MAX_TASKS_PER_PLAYER];
} player_t;

player_t players[MAX_PLAYERS];
int num_players = 0;

void add_player() {
    if (num_players >= MAX_PLAYERS) {
        printf("Sorry, maximum number of players reached\n");
        return;
    }
    player_t player;
    player.player_id = num_players + 1;
    player.num_tasks = 0;
    players[num_players] = player;
    num_players++;
    printf("New player added with ID %d\n", player.player_id);
}

void add_task() {
    int player_id, priority, time_required;
    printf("Enter player ID: ");
    scanf("%d", &player_id);
    if (player_id < 1 || player_id > num_players) {
        printf("Invalid player ID\n");
        return;
    }
    printf("Enter task priority [1-10]: ");
    scanf("%d", &priority);
    if (priority < 1 || priority > 10) {
        printf("Invalid task priority\n");
        return;
    }
    printf("Enter time required to complete task [1-10]: ");
    scanf("%d", &time_required);
    if (time_required < 1 || time_required > 10) {
        printf("Invalid time required\n");
        return;
    }
    player_t *player = &players[player_id - 1];
    if (player->num_tasks >= MAX_TASKS_PER_PLAYER) {
        printf("Sorry, maximum number of tasks reached for this player\n");
        return;
    }
    task_t task;
    task.task_id = player->num_tasks + 1;
    task.priority = priority;
    task.player_id = player_id;
    task.time_required = time_required;
    player->tasks[player->num_tasks] = task;
    player->num_tasks++;
    printf("New task added for player %d with ID %d\n", player_id, task.task_id);
}

void print_tasks() {
    printf("\nTASKS:\n");
    for (int i = 0; i < num_players; i++) {
        player_t *player = &players[i];
        printf("Player%d:\n", player->player_id);
        for (int j = 0; j < player->num_tasks; j++) {
            task_t *task = &player->tasks[j];
            printf("  Task%d: priority=%d, time_required=%d\n", task->task_id, task->priority, task->time_required);
        }
    }
}

void schedule_tasks() {
    int total_time = 0;
    int max_time = 0;
    for (int i = 0; i < num_players; i++) {
        player_t *player = &players[i];
        for (int j = 0; j < player->num_tasks; j++) {
            max_time = max_time < player->tasks[j].time_required ? player->tasks[j].time_required : max_time;
        }
    }
    printf("Max time required for a single task: %d\n", max_time);

    while (total_time < 60*60*8) {
        int min_priority = 11;
        player_t *min_player = NULL;
        task_t *min_task = NULL;

        for (int i = 0; i < num_players; i++) {
            player_t *player = &players[i];
            for (int j = 0; j < player->num_tasks; j++) {
                task_t *task = &player->tasks[j];
                if (task->priority < min_priority) {
                    min_priority = task->priority;
                    min_player = player;
                    min_task = task;
                }
            }
        }

        if (min_player == NULL || min_task == NULL) {
            break;
        }

        if (total_time + min_task->time_required <= 60*60*8) {
            printf("Executing task%d of player%d for %d seconds\n", min_task->task_id, min_task->player_id, min_task->time_required);
            total_time += min_task->time_required;
            min_player->num_tasks--;
            *min_task = min_player->tasks[min_player->num_tasks];
        } else {
            printf("Cannot execute task%d of player%d due to time constraint\n", min_task->task_id, min_task->player_id);
            break;
        }
    }

    printf("Total time used: %d seconds\n", total_time);
}

int main() {
    srand(time(NULL));
    while (1) {
        printf("\nChoose an option from the menu:\n");
        printf("1. Add player\n");
        printf("2. Add task\n");
        printf("3. Schedule tasks\n");
        printf("4. Print tasks\n");
        printf("5. Quit\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_player();
                break;
            case 2:
                add_task();
                break;
            case 3:
                schedule_tasks();
                break;
            case 4:
                print_tasks();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}