//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_NETS 5000

/* declare global variables */
int num_nodes = 0;
int num_nets = 0;

int nodes[MAX_NODES];
int nets[MAX_NETS][3];

float x[MAX_NODES];
float y[MAX_NODES];

float l[MAX_NETS];
float c[MAX_NETS];
float r[MAX_NETS];

float ts[MAX_NETS];
float vs[MAX_NETS];

float frequencies[] = { 1, 10, 100, 1000, 10000, 100000 };
int num_frequencies = 6;

/* function to do AC simulation */
void simulateAC() {
    for (int i = 0; i < num_frequencies; i++) {
        float w = 2 * M_PI * frequencies[i];

        for (int j = 0; j < num_nets; j++) {
            float lmn = l[j] * w;
            float cmn = c[j] * w;
            float rmn = r[j];

            float zx = rmn + 2 * lmn / (cmn * cmn * w * w);
            float zy = 1 / (cmn * w);

            float v = vs[j] / (1 + zx * zy);
            float i = v / zx;

            ts[j] = sqrt((v * v + i * i * zx * zx) * cmn * cmn);
        }

        printf("AC simulation results for frequency %fHz:\n", frequencies[i]);
        for (int j = 0; j < num_nets; j++) {
            printf("Net %d: %.2fV, %.2fmA\n", j, ts[j], ts[j] * w);
        }
    }
}

/* main function */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <netlist file>\n", argv[0]);
        exit(1);
    }

    /* open netlist file */
    FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Error: cannot open file %s\n", argv[1]);
        exit(1);
    }

    /* parse netlist file */
    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        if (line[0] == 'R') { /* resistor */
            sscanf(line, "R%d %d %d %f", &nets[num_nets][0], &nets[num_nets][1], &nets[num_nets][2], &r[num_nets]);
            num_nets++;
        } else if (line[0] == 'L') { /* inductor */
            sscanf(line, "L%d %d %d %f", &nets[num_nets][0], &nets[num_nets][1], &nets[num_nets][2], &l[num_nets]);
            num_nets++;
        } else if (line[0] == 'C') { /* capacitor */
            sscanf(line, "C%d %d %d %f", &nets[num_nets][0], &nets[num_nets][1], &nets[num_nets][2], &c[num_nets]);
            num_nets++;
        } else if (line[0] == 'V') { /* voltage source */
            sscanf(line, "V%d %d %d %f", &nets[num_nets][0], &nets[num_nets][1], &nets[num_nets][2], &vs[num_nets]);
            num_nets++;
        }
    }

    /* close netlist file */
    fclose(fp);

    /* find unique nodes */
    for (int i = 0; i < num_nets; i++) {
        for (int j = 0; j < 2; j++) {
            int node = nets[i][j];
            int found = 0;

            for (int k = 0; k < num_nodes; k++) {
                if (nodes[k] == node) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                nodes[num_nodes++] = node;
            }
        }
    }

    /* print nodes */
    printf("Nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d\n", nodes[i]);
    }

    /* prompt user for node locations */
    printf("Enter node locations:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: ", nodes[i]);
        scanf("%f %f", &x[i], &y[i]);
    }

    /* print nets */
    printf("Nets:\n");
    for (int i = 0; i < num_nets; i++) {
        printf("Net %d: %d %d %d\n", i, nets[i][0], nets[i][1], nets[i][2]);
    }

    /* do AC simulation */
    simulateAC();

    return 0;
}