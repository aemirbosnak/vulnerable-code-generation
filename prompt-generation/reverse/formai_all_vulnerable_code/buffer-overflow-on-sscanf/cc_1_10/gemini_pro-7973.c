//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int y, m, d, h, min;
} date_time_t;

typedef struct {
    char name[30];
    date_time_t start;
    date_time_t end;
} appointment_t;

#define MAX_APPOINTMENTS 50

static appointment_t appointments[MAX_APPOINTMENTS];
static int num_appointments = 0;

static void print_appointment(appointment_t *a) {
    printf("%s: %04d-%02d-%02d %02d:%02d - %04d-%02d-%02d %02d:%02d\n",
           a->name, a->start.y, a->start.m, a->start.d, a->start.h, a->start.min,
           a->end.y, a->end.m, a->end.d, a->end.h, a->end.min);
}

static int compare_appointments(const void *a, const void *b) {
    const appointment_t *a1 = (const appointment_t *)a;
    const appointment_t *a2 = (const appointment_t *)b;
    int cmp = strcmp(a1->name, a2->name);
    if (cmp == 0) {
        cmp = memcmp(&a1->start, &a2->start, sizeof(date_time_t));
    }
    return cmp;
}

static void sort_appointments() {
    qsort(appointments, num_appointments, sizeof(appointment_t), compare_appointments);
}

static int find_free_slot(date_time_t start, date_time_t end) {
    int i;
    for (i = 0; i < num_appointments; i++) {
        if (appointments[i].start.y > end.y ||
            (appointments[i].start.y == end.y && appointments[i].start.m > end.m) ||
            (appointments[i].start.y == end.y && appointments[i].start.m == end.m && appointments[i].start.d > end.d) ||
            (appointments[i].start.y == end.y && appointments[i].start.m == end.m && appointments[i].start.d == end.d && appointments[i].start.h > end.h) ||
            (appointments[i].start.y == end.y && appointments[i].start.m == end.m && appointments[i].start.d == end.d && appointments[i].start.h == end.h && appointments[i].start.min > end.min)) {
            break;
        }
    }
    return i;
}

int main() {
    int i;
    char line[100];

    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (line[0] == '\n') {
            break;
        }

        appointment_t a;
        sscanf(line, "%s %d-%d-%d %d:%d - %d-%d-%d %d:%d",
               a.name, &a.start.y, &a.start.m, &a.start.d, &a.start.h, &a.start.min,
               &a.end.y, &a.end.m, &a.end.d, &a.end.h, &a.end.min);

        if (find_free_slot(a.start, a.end) == num_appointments) {
            printf("Sorry, no free slots available.\n");
            continue;
        }

        appointments[num_appointments++] = a;
    }

    sort_appointments();

    for (i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    return 0;
}