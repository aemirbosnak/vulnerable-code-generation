//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_BRANCHES 2000

int num_nodes = 0, num_branches = 0, num_v_sources = 0, num_i_sources = 0;
double node_voltage[MAX_NODES];
double branch_current[MAX_BRANCHES];
double G[MAX_NODES][MAX_NODES], B[MAX_NODES][MAX_NODES];
double E[MAX_NODES][MAX_BRANCHES], F[MAX_BRANCHES][MAX_NODES];

void parse_input_file(const char *input_file_path) {
    FILE *input_file = fopen(input_file_path, "r");
    if (!input_file) {
        printf("File not found\n");
        exit(1);
    }
    fscanf(input_file, "%d %d", &num_nodes, &num_branches);
    char source_type;
    int node1, node2;
    double value;
    for (int i = 0; i < num_branches; i++) {
        fscanf(input_file, "%c %d %d %lf", &source_type, &node1, &node2, &value);
        if (source_type == 'R') {
            int branch_index = i - num_v_sources - num_i_sources;
            F[branch_index][node1-1] = 1.0/value;
            F[branch_index][node2-1] = -1.0/value;
            G[node1-1][node1-1] += 1.0/value;
            G[node1-1][node2-1] -= 1.0/value;
            G[node2-1][node2-1] += 1.0/value;
            G[node2-1][node1-1] -= 1.0/value;
        } else if (source_type == 'V') {
            E[node1-1][num_v_sources] = 1.0;
            E[node2-1][num_v_sources] = -1.0;
            F[num_branches-num_i_sources+num_v_sources][node1-1] = -1.0;
            F[num_branches-num_i_sources+num_v_sources][node2-1] = 1.0;
            E[num_branches-num_i_sources+num_v_sources][num_v_sources] = 1.0;
            num_v_sources++;
        } else {
            E[node1-1][i-num_v_sources] = 1.0;
            E[node2-1][i-num_v_sources] = -1.0;
            F[i-num_v_sources][node1-1] = -value;
            F[i-num_v_sources][node2-1] = value;
            num_i_sources++;
        }
    }
    fclose(input_file);
}

void print_solution() {
    printf("Node Voltages:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %lf\n", i+1, node_voltage[i]);
    }
    printf("Branch Currents:\n");
    for (int i = 0; i < num_branches; i++) {
        printf("Branch %d: %lf\n", i+1, branch_current[i]);
    }
}

void solve() {
    double M[MAX_NODES + MAX_BRANCHES][MAX_NODES + MAX_BRANCHES];
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            M[i][j] = G[i][j];
        }
        for (int j = 0; j < num_branches; j++) {
            M[i][j+num_nodes] = -F[j][i];
        }
    }
    for (int i = 0; i < num_branches; i++) {
        for (int j = 0; j < num_nodes; j++) {
            M[i+num_nodes][j] = E[j][i];
        }
        for (int j = 0; j < num_branches; j++) {
            M[i+num_nodes][j+num_nodes] = 0.0;
        }
        M[i+num_nodes][i+num_nodes] = -1.0;
    }
    double Y[MAX_NODES + MAX_BRANCHES][MAX_NODES + MAX_BRANCHES];
    for (int i = 0; i < num_nodes + num_branches; i++) {
        for (int j = 0; j < num_nodes + num_branches; j++) {
            Y[i][j] = M[i][j];
        }
    }
    for (int i = 0; i < num_nodes + num_branches; i++) {
        double max_element = Y[i][i];
        int leading_row = i;
        for (int j = i+1; j < num_nodes + num_branches; j++) {
            if (abs(Y[j][i]) > abs(max_element)) {
                max_element = Y[j][i];
                leading_row = j;
            }
        }
        for (int j = i; j < num_nodes + num_branches; j++) {
            double temp = Y[leading_row][j];
            Y[leading_row][j] = Y[i][j];
            Y[i][j] = temp;
        }
        for (int j = i+1; j < num_nodes + num_branches; j++) {
            double factor = Y[j][i] / Y[i][i];
            for (int k = i; k < num_nodes + num_branches; k++) {
                Y[j][k] -= factor * Y[i][k];
            }
        }
    }
    for (int i = num_nodes + num_branches - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i+1; j < num_nodes + num_branches; j++) {
            sum += Y[i][j] * node_voltage[j-num_nodes];
        }
        node_voltage[i] = (Y[i][num_nodes + num_branches] - sum) / Y[i][i];
    }
    for (int i = 0; i < num_branches; i++) {
        double sum = 0.0;
        for (int j = 0; j < num_nodes; j++) {
            sum += F[i][j] * node_voltage[j];
        }
        branch_current[i] = sum;
    }
}

int main() {
    parse_input_file("circuit.txt");
    solve();
    print_solution();
    return 0;
}