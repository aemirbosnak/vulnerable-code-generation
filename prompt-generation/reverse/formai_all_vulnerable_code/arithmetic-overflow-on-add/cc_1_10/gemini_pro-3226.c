//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 10000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 255

struct appointment {
	time_t start;
	time_t end;
	char name[MAX_NAME_LENGTH + 1];
	char description[MAX_DESCRIPTION_LENGTH + 1];
};

struct appointment_scheduler {
	struct appointment *appointments[MAX_APPOINTMENTS];
	int num_appointments;
	int cleared;
};

struct appointment_scheduler *appointment_scheduler_new() {
	struct appointment_scheduler *scheduler = malloc(sizeof(struct appointment_scheduler));
	if (scheduler == NULL) {
		return NULL;
	}

	scheduler->num_appointments = 0;
	scheduler->cleared = false;

	return scheduler;
}

void appointment_scheduler_free(struct appointment_scheduler *scheduler) {
	if (scheduler == NULL) {
		return;
	}

	for (int i = 0; i < scheduler->num_appointments; i++) {
		free(scheduler->appointments[i]);
	}

	free(scheduler);
}

struct appointment *appointment_new(time_t start, time_t end, char *name, char *description) {
	struct appointment *appointment = malloc(sizeof(struct appointment));
	if (appointment == NULL) {
		return NULL;
	}

	appointment->start = start;
	appointment->end = end;
	strncpy(appointment->name, name, MAX_NAME_LENGTH);
	strncpy(appointment->description, description, MAX_DESCRIPTION_LENGTH);

	return appointment;
}

void appointment_free(struct appointment *appointment) {
	if (appointment == NULL) {
		return;
	}

	free(appointment);
}

bool appointment_scheduler_add_appointment(struct appointment_scheduler *scheduler, struct appointment *appointment) {
	if (scheduler == NULL || appointment == NULL) {
		return false;
	}

	if (scheduler->num_appointments == MAX_APPOINTMENTS) {
		return false;
	}

	scheduler->appointments[scheduler->num_appointments++] = appointment;

	return true;
}

struct appointment *appointment_scheduler_find_appointment(struct appointment_scheduler *scheduler, time_t start, time_t end) {
	if (scheduler == NULL) {
		return NULL;
	}

	for (int i = 0; i < scheduler->num_appointments; i++) {
		struct appointment *appointment = scheduler->appointments[i];
		if (appointment->start == start && appointment->end == end) {
			return appointment;
		}
	}

	return NULL;
}

bool appointment_scheduler_delete_appointment(struct appointment_scheduler *scheduler, struct appointment *appointment) {
	if (scheduler == NULL || appointment == NULL) {
		return false;
	}

	for (int i = 0; i < scheduler->num_appointments; i++) {
		if (scheduler->appointments[i] == appointment) {
			scheduler->appointments[i] = scheduler->appointments[scheduler->num_appointments - 1];
			scheduler->num_appointments--;
			return true;
		}
	}

	return false;
}

void appointment_scheduler_print(struct appointment_scheduler *scheduler) {
	if (scheduler == NULL) {
		return;
	}

	for (int i = 0; i < scheduler->num_appointments; i++) {
		struct appointment *appointment = scheduler->appointments[i];
		printf("Appointment %d:\n", i + 1);
		printf("  Start: %s", ctime(&appointment->start));
		printf("  End: %s", ctime(&appointment->end));
		printf("  Name: %s", appointment->name);
		printf("  Description: %s", appointment->description);
		printf("\n");
	}
}

int main() {
	struct appointment_scheduler *scheduler = appointment_scheduler_new();

	struct appointment *appointment1 = appointment_new(time(NULL) + 3600, time(NULL) + 7200, "Doctor's appointment", "Annual checkup");
	struct appointment *appointment2 = appointment_new(time(NULL) + 86400, time(NULL) + 108000, "Meeting with boss", "Discuss performance review");
	struct appointment *appointment3 = appointment_new(time(NULL) + 172800, time(NULL) + 216000, "Vacation", "Going to the beach");

	appointment_scheduler_add_appointment(scheduler, appointment1);
	appointment_scheduler_add_appointment(scheduler, appointment2);
	appointment_scheduler_add_appointment(scheduler, appointment3);

	appointment_scheduler_print(scheduler);

	printf("\n");

	struct appointment *appointment4 = appointment_scheduler_find_appointment(scheduler, time(NULL) + 86400, time(NULL) + 108000);
	if (appointment4 != NULL) {
		printf("Found appointment:\n");
		printf("  Start: %s", ctime(&appointment4->start));
		printf("  End: %s", ctime(&appointment4->end));
		printf("  Name: %s", appointment4->name);
		printf("  Description: %s", appointment4->description);
		printf("\n");
	} else {
		printf("No appointment found.\n");
	}

	printf("\n");

	appointment_scheduler_delete_appointment(scheduler, appointment3);

	appointment_scheduler_print(scheduler);

	appointment_scheduler_free(scheduler);

	return 0;
}