//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Romeo and Juliet
// Romeo and Juliet Circuit Simulator
 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define MAX_GATE 1000
#define PI 3.14159265358979323846
 
typedef struct Gate {
    char type[10];
    int qubits[3];
} Gate;
 
void applyNot(Gate g, int* state) {
    int control = g.qubits[0];
    int target = g.qubits[1];
    int x = (1 << target);
    if ((((*state) & (1 << control)) >> control) == 1) {
        *state ^= x;
    }
}
 
void applyCNot(Gate g, int* state) {
    int control = g.qubits[0];
    int target = g.qubits[1];
    int x = (1 << target);
    int ctrlState = ((*state) & (1 << control)) >> control;
    if (ctrlState == 1) {
        *state ^= x;
    }
}
 
void applyToffoli(Gate g, int* state) {
    int control1 = g.qubits[0];
    int control2 = g.qubits[1];
    int target = g.qubits[2];
    int x = (1 << target);
    if ((((*state) & (1 << control1)) >> control1) == 1 &&
        (((*state) & (1 << control2)) >> control2) == 1) {
        *state ^= x;
    }
}
 
void applyGate(Gate g, int* state) {
    if (strcmp(g.type, "not") == 0) {
        applyNot(g, state);
    }
    else if (strcmp(g.type, "cnot") == 0) {
        applyCNot(g, state);
    }
    else if (strcmp(g.type, "toffoli") == 0) {
        applyToffoli(g, state);
    }
}
 
void initState(char* stateStr, int* state) {
    size_t len = strlen(stateStr);
    for (int i = 0; i < len; i++) {
        if (stateStr[i] == '1') {
            *state += (int)pow(2, len - i - 1);
        }
    }
}
 
void printState(int state) {
    int n = (int)(log2(state) + 1);
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", (state & (1 << i)) >> i);
    }
}
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char stateStr[100];
    scanf("%s", stateStr);
    int state = 0;
    initState(stateStr, &state);
    Gate gates[MAX_GATE];
    for (int i = 0; i < m; i++) {
        scanf("%s", gates[i].type);
        if (strcmp(gates[i].type, "not") == 0) {
            scanf("%d", &gates[i].qubits[0]);
            gates[i].qubits[1] = -1;
        }
        else if (strcmp(gates[i].type, "cnot") == 0) {
            scanf("%d %d", &gates[i].qubits[0], &gates[i].qubits[1]);
        }
        else if (strcmp(gates[i].type, "toffoli") == 0) {
            scanf("%d %d %d", &gates[i].qubits[0], &gates[i].qubits[1], &gates[i].qubits[2]);
        }
    }
    for (int i = 0; i < m; i++) {
        applyGate(gates[i], &state);
    }
    printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
    printf("Deny thy father and refuse thy name;\n");
    printf("Or, if thou wilt not, be but sworn my love,\n");
    printf("And I'll no longer be a Circuit Simulator.\n");
    printf("State after circuit: ");
    printState(state);
    printf("\n");
    return 0;
}