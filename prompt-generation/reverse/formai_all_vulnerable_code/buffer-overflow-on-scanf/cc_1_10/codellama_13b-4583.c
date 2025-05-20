//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
void main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process {
        int pid;
        int arrival_time;
        int burst_time;
        int priority;
    } p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", p[i].pid);
        scanf("%d", &p[i].arrival_time);
        printf("Enter burst time for process %d: ", p[i].pid);
        scanf("%d", &p[i].burst_time);
        printf("Enter priority for process %d: ", p[i].pid);
        scanf("%d", &p[i].priority);
    }
    // Sort processes by arrival time
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival_time > p[j].arrival_time) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    // Sort processes by priority
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].priority < p[j].priority) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    // Schedule processes
    int curr_time = 0;
    int total_burst_time = 0;
    for (int i = 0; i < n; i++) {
        if (curr_time >= p[i].arrival_time) {
            printf("Process %d is running\n", p[i].pid);
            curr_time += p[i].burst_time;
            total_burst_time += p[i].burst_time;
            printf("Total burst time: %d\n", total_burst_time);
        }
    }
}