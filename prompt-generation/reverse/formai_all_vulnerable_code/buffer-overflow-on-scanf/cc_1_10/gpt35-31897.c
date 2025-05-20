//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h> 
#define MAX_NETWORK_DEVICES 10
#define MAX_TRAFFIC_TYPES 5

typedef struct device {
    int device_id;
    float uplink_bandwidth;
    float downlink_bandwidth;
    float latency;
    float packet_loss_rate;
} Device;

typedef struct traffic_type {
    int traffic_id;
    float bandwidth_requirement;
    float jitter_tolerance;
    float packet_loss_tolerance;
} TrafficType;

typedef struct qos_parameters {
    Device devices[MAX_NETWORK_DEVICES];
    TrafficType traffic_types[MAX_TRAFFIC_TYPES];
    int num_devices;
    int num_traffic_types;
} QoSparameters;

void initialize_devices(Device* devices, int num_devices) {
    for(int i = 0; i < num_devices; i++) {
        devices[i].device_id = i+1;
        devices[i].uplink_bandwidth = (float)rand()/(float)(RAND_MAX/10.0); // random values between 0 and 10
        devices[i].downlink_bandwidth = (float)rand()/(float)(RAND_MAX/10.0);
        devices[i].latency = (float)rand()/(float)(RAND_MAX/100.0); // random values between 0 and 0.01
        devices[i].packet_loss_rate = (float)rand()/(float)(RAND_MAX/0.1); // random values between 0 and 0.1
    }
}

void initialize_traffic_types(TrafficType* traffic_types, int num_traffic_types) {
    for(int i = 0; i < num_traffic_types; i++) {
        traffic_types[i].traffic_id = i+1;
        traffic_types[i].bandwidth_requirement = (float)rand()/(float)(RAND_MAX/10.0);
        traffic_types[i].jitter_tolerance = (float)rand()/(float)(RAND_MAX/0.01); // random values between 0 and 0.01
        traffic_types[i].packet_loss_tolerance = (float)rand()/(float)(RAND_MAX/0.02); // random values between 0 and 0.02
    }
}

void print_devices(Device* devices, int num_devices) {
    printf("ID\tUplink Bandwidth\tDownlink Bandwidth\tLatency\tPacket Loss Rate\n");
    for(int i = 0; i < num_devices; i++) {
        printf("%d\t%f\t%f\t%f\t%f\n", devices[i].device_id, devices[i].uplink_bandwidth, devices[i].downlink_bandwidth, devices[i].latency, devices[i].packet_loss_rate);
    }
}

void print_traffic_types(TrafficType* traffic_types, int num_traffic_types) {
    printf("ID\tBandwidth Requirement\tJitter Tolerance\tPacket Loss Tolerance\n");
    for(int i = 0; i < num_traffic_types; i++) {
        printf("%d\t%f\t%f\t%f\n", traffic_types[i].traffic_id, traffic_types[i].bandwidth_requirement, traffic_types[i].jitter_tolerance, traffic_types[i].packet_loss_tolerance);
    }
}

void get_qos_params(QoSparameters* qos_params) {
    printf("Enter the number of devices: ");
    scanf("%d", &qos_params->num_devices);
    initialize_devices(qos_params->devices, qos_params->num_devices);
    print_devices(qos_params->devices, qos_params->num_devices);
    
    printf("\nEnter the number of traffic types: ");
    scanf("%d", &qos_params->num_traffic_types);
    initialize_traffic_types(qos_params->traffic_types, qos_params->num_traffic_types);
    print_traffic_types(qos_params->traffic_types, qos_params->num_traffic_types);
}

int main() {
    QoSparameters qos_params;
    get_qos_params(&qos_params);
    return 0;
}