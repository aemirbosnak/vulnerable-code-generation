//Falcon2-11B DATASET v1.0 Category: Time Travel Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 3000

struct Time {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

void set_time(struct Time *time, int year, int month, int day, int hour, int minute, int second) {
    time->year = year;
    time->month = month;
    time->day = day;
    time->hour = hour;
    time->minute = minute;
    time->second = second;
}

void print_time(struct Time *time) {
    printf("%d-%d-%d %d:%d:%d\n", time->year, time->month, time->day, time->hour, time->minute, time->second);
}

void time_travel(struct Time *current_time, int year, int month, int day, int hour, int minute, int second) {
    struct Time *new_time = malloc(sizeof(struct Time));
    set_time(new_time, year, month, day, hour, minute, second);

    // Move to the future
    if (year > current_time->year) {
        if (month > current_time->month) {
            if (day > current_time->day) {
                if (hour > current_time->hour) {
                    if (minute > current_time->minute) {
                        if (second > current_time->second) {
                            printf("You have traveled too far into the future!\n");
                        } else {
                            new_time->second = second;
                        }
                    } else {
                        new_time->minute = minute;
                    }
                } else {
                    new_time->hour = hour;
                }
            } else {
                new_time->day = day;
            }
        } else {
            new_time->month = month;
        }
    } else if (year < current_time->year) {
        if (month > current_time->month) {
            if (day > current_time->day) {
                if (hour > current_time->hour) {
                    if (minute > current_time->minute) {
                        if (second > current_time->second) {
                            printf("You have traveled too far into the past!\n");
                        } else {
                            new_time->second = second;
                        }
                    } else {
                        new_time->minute = minute;
                    }
                } else {
                    new_time->hour = hour;
                }
            } else {
                new_time->day = day;
            }
        } else {
            new_time->month = month;
        }
    } else {
        if (day > current_time->day) {
            if (hour > current_time->hour) {
                if (minute > current_time->minute) {
                    if (second > current_time->second) {
                        printf("You have traveled too far into the future!\n");
                    } else {
                        new_time->second = second;
                    }
                } else {
                    new_time->minute = minute;
                }
            } else {
                new_time->hour = hour;
            }
        } else {
            if (hour > current_time->hour) {
                if (minute > current_time->minute) {
                    if (second > current_time->second) {
                        printf("You have traveled too far into the future!\n");
                    } else {
                        new_time->second = second;
                    }
                } else {
                    new_time->minute = minute;
                }
            } else {
                if (minute > current_time->minute) {
                    if (second > current_time->second) {
                        printf("You have traveled too far into the future!\n");
                    } else {
                        new_time->second = second;
                    }
                } else {
                    new_time->minute = minute;
                }
            }
        }
    }

    // Move to the past
    if (year < current_time->year) {
        if (month < current_time->month) {
            if (day < current_time->day) {
                if (hour < current_time->hour) {
                    if (minute < current_time->minute) {
                        if (second < current_time->second) {
                            printf("You have traveled too far into the past!\n");
                        } else {
                            new_time->second = second;
                        }
                    } else {
                        new_time->minute = minute;
                    }
                } else {
                    new_time->hour = hour;
                }
            } else {
                new_time->day = day;
            }
        } else {
            new_time->month = month;
        }
    } else if (year > current_time->year) {
        if (month < current_time->month) {
            if (day < current_time->day) {
                if (hour < current_time->hour) {
                    if (minute < current_time->minute) {
                        if (second < current_time->second) {
                            printf("You have traveled too far into the past!\n");
                        } else {
                            new_time->second = second;
                        }
                    } else {
                        new_time->minute = minute;
                    }
                } else {
                    new_time->hour = hour;
                }
            } else {
                new_time->day = day;
            }
        } else {
            new_time->month = month;
        }
    } else {
        if (day < current_time->day) {
            if (hour < current_time->hour) {
                if (minute < current_time->minute) {
                    if (second < current_time->second) {
                        printf("You have traveled too far into the past!\n");
                    } else {
                        new_time->second = second;
                    }
                } else {
                    new_time->minute = minute;
                }
            } else {
                if (hour < current_time->hour) {
                    if (minute < current_time->minute) {
                        if (second < current_time->second) {
                            printf("You have traveled too far into the past!\n");
                        } else {
                            new_time->second = second;
                        }
                    } else {
                        new_time->minute = minute;
                    }
                } else {
                    if (minute < current_time->minute) {
                        if (second < current_time->second) {
                            printf("You have traveled too far into the past!\n");
                        } else {
                            new_time->second = second;
                        }
                    } else {
                        new_time->minute = minute;
                    }
                }
            }
        } else {
            if (hour < current_time->hour) {
                if (minute < current_time->minute) {
                    if (second < current_time->second) {
                        printf("You have traveled too far into the past!\n");
                    } else {
                        new_time->second = second;
                    }
                } else {
                    new_time->minute = minute;
                }
            } else {
                if (minute < current_time->minute) {
                    if (second < current_time->second) {
                        printf("You have traveled too far into the past!\n");
                    } else {
                        new_time->second = second;
                    }
                } else {
                    new_time->minute = minute;
                }
            }
        }
    }

    // Update current time
    free(current_time);
    current_time = new_time;
}

int main() {
    struct Time current_time;
    set_time(&current_time, 2023, 5, 15, 10, 30, 45);
    print_time(&current_time);

    int year, month, day, hour, minute, second;
    printf("Enter the year, month, day, hour, minute, and second you want to travel to: ");
    scanf("%d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &second);
    time_travel(&current_time, year, month, day, hour, minute, second);

    print_time(&current_time);
    return 0;
}