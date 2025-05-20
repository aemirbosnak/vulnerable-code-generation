//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double r;
    double c;
    double v;
    double i;
} RC;

void RC_init(RC *rc, double r, double c) {
    rc->r = r;
    rc->c = c;
    rc->v = 0.0;
    rc->i = 0.0;
}

void RC_step(RC *rc, double dt) {
    double dv = -rc->v / rc->r;
    double di = -dv / rc->c;
    rc->v += dv * dt;
    rc->i += di * dt;
}

int main() {
    int n;
    printf("Enter the number of RC circuits: ");
    scanf("%d", &n);

    RC *rcs = malloc(n * sizeof(RC));

    for (int i = 0; i < n; i++) {
        printf("Enter the resistance (ohms) for circuit %d: ", i+1);
        scanf("%lf", &rcs[i].r);
        printf("Enter the capacitance (farads) for circuit %d: ", i+1);
        scanf("%lf", &rcs[i].c);
    }

    printf("Enter the time step (seconds): ");
    double dt = scanf("%lf", &dt);

    for (int t = 0; t < 1000; t++) {
        for (int i = 0; i < n; i++) {
            RC_step(&rcs[i], dt);
        }
        printf("%d\t", t);
        for (int i = 0; i < n; i++) {
            printf("%lf\t", rcs[i].v);
        }
        printf("\n");
    }

    return 0;
}