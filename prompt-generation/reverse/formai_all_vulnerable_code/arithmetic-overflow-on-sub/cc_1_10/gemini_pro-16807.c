//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

struct task {
	void (*func)(void);
	time_t when;
};

struct task_scheduler {
	struct task *tasks;
	int num_tasks;
	int next_task;
};

static void task_scheduler_init(struct task_scheduler *scheduler)
{
	scheduler->tasks = NULL;
	scheduler->num_tasks = 0;
	scheduler->next_task = 0;
}

static void task_scheduler_destroy(struct task_scheduler *scheduler)
{
	if (scheduler->tasks) {
		free(scheduler->tasks);
		scheduler->tasks = NULL;
	}
	scheduler->num_tasks = 0;
	scheduler->next_task = 0;
}

static int task_scheduler_add_task(struct task_scheduler *scheduler, void (*func)(void), time_t when)
{
	if (scheduler->tasks == NULL) {
		scheduler->tasks = malloc(sizeof(*scheduler->tasks));
		if (scheduler->tasks == NULL) {
			return -1;
		}
		scheduler->num_tasks = 1;
	} else {
		scheduler->tasks = realloc(scheduler->tasks, (scheduler->num_tasks + 1) * sizeof(*scheduler->tasks));
		if (scheduler->tasks == NULL) {
			return -1;
		}
		scheduler->num_tasks++;
	}
	scheduler->tasks[scheduler->num_tasks - 1].func = func;
	scheduler->tasks[scheduler->num_tasks - 1].when = when;
	return 0;
}

static void task_scheduler_run(struct task_scheduler *scheduler)
{
	while (scheduler->next_task < scheduler->num_tasks) {
		time_t now = time(NULL);
		if (now >= scheduler->tasks[scheduler->next_task].when) {
			scheduler->tasks[scheduler->next_task].func();
			scheduler->next_task++;
		} else {
			sleep(scheduler->tasks[scheduler->next_task].when - now);
		}
	}
}

static void task1(void)
{
	printf("Task 1 executed.\n");
}

static void task2(void)
{
	printf("Task 2 executed.\n");
}

int main(void)
{
	struct task_scheduler scheduler;
	task_scheduler_init(&scheduler);
	task_scheduler_add_task(&scheduler, task1, time(NULL) + 1);
	task_scheduler_add_task(&scheduler, task2, time(NULL) + 3);
	task_scheduler_run(&scheduler);
	task_scheduler_destroy(&scheduler);
	return 0;
}